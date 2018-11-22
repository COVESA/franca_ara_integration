#include <QImageReader>
#include <QElapsedTimer>
#include <QDebug>

#include "imagesource.h"

#define IMAGE_FEED_PATH "/usr/share/franca-ara"

void ImageSource::run()
{
    uint8_t imagecount = 0;
    QElapsedTimer timer;
    timer.start();

    while (true) {
        QImageReader reader(QString("%1/l_image%2.png").arg(IMAGE_FEED_PATH).arg(imagecount++));
        emit imageReady(reader.read());

        msleep(20);

        /* wrap around */
        if ((imagecount % 228) == 0) {
            imagecount = 0;

            qDebug() << "Image sequence total playtime: " << timer.elapsed()/1000 << "seconds";
            timer.restart();
        }
    }
}
