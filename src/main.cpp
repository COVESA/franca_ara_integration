// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project

#include <QGuiApplication>
#undef QT_OPENGL_ES_3
#include <QQuickView>
#include <QQmlEngine>
#include <QQmlContext>

#include "SomeIpNetworkThread.h"
#include "imageprovider.h"

#include <dlt.h>

#include "dltloggername.h"

DLT_DECLARE_CONTEXT(DLT_FRA_ARA_CONTEXT)

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQuickView view;

    DLT_REGISTER_APP("FRA","FRANCA-ARA Integration Demo");
    DLT_REGISTER_CONTEXT(dl_fra_ara,"CON","First context");

    DLT_LOG(dl_fra_ara,DLT_LOG_INFO,DLT_STRING("Hello world!"));

    setenv("QT_QPA_PLATFORM", "wayland", 1);
    setenv("QT_WAYLAND_DISABLE_WINDOWDECORATION", "1", 1);

    SomeIpNetworkThread *network_thread = new SomeIpNetworkThread();
    network_thread->connections(view);

    view.engine()->addImportPath(QCoreApplication::applicationDirPath() +
                                 "/imports");
    view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view.show();

    network_thread->start();

    return app.exec();
}
