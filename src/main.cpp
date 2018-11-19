#include <QGuiApplication>
#undef QT_OPENGL_ES_3
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>

#include "SomeIpNetworkThread.h"
#include "imageprovider.h"

int main(int argc, char *argv[])
{
    ImageProvider *provider = new ImageProvider;
    QGuiApplication app(argc, argv);
    QQuickView view;

    setenv("QT_QPA_PLATFORM", "wayland", 1);
    setenv("QT_WAYLAND_DISABLE_WINDOWDECORATION", "1", 1);

    view.engine()->addImportPath(QCoreApplication::applicationDirPath() + "/imports");

    view.engine()->addImageProvider("imageprovider", provider);
    view.engine()->rootContext()->setContextProperty("imageprovider", provider);

    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view.show();

    SomeIpNetworkThread *network_thread = new SomeIpNetworkThread();
    QObject::connect(network_thread, SIGNAL(imageReady(const QImage&)),
            provider, SLOT(setImage(const QImage&)));

    network_thread->start();

    return app.exec();
}
