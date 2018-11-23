#include "imageprovider.h"
#include <iostream>

#include "dltlogger.h"

ImageProvider::ImageProvider(QObject* parent) :  QObject(parent), QQuickImageProvider(QQuickImageProvider::Pixmap)
{
}

ImageProvider::~ImageProvider()
{
}

QPixmap ImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    Q_UNUSED(id);
    Q_UNUSED(size);
    QPixmap pixmap;

    DLT_LOG(DLT_FRA_ARA_CONTEXT, DLT_LOG_DEBUG, DLT_STRING("requestPixmap()!"));

    if (m_image.isNull())
      return QPixmap();

    pixmap = QPixmap::fromImage(m_image);

    if (requestedSize.width() > 0)
        pixmap = pixmap.scaledToWidth(requestedSize.width());

    if (requestedSize.height() > 0)
        pixmap = pixmap.scaledToHeight(requestedSize.height());

    return pixmap;
}

void ImageProvider::setImage(const QImage &img)
{
    DLT_LOG(DLT_FRA_ARA_CONTEXT, DLT_LOG_DEBUG, DLT_STRING("setImage()!"));
    m_image = img;
    emit updateGraphicsImage(); // to QML thread
}
