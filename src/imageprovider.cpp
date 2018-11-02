#include "imageprovider.h"

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
    m_image = img;
    emit newFrameReceived();
}
