#include "imagesource.h"

void ImageSource::run()
{
    QImage im1 = QImage(":img/GENIVI_Black_Logo-white_background.jpg");
    QImage im2 = QImage(":img/GENIVI_White_Logo-black_background.jpg");

    while (true) {
        emit imageReady(im1);
        sleep(1);
        emit imageReady(im2);
        sleep(1);
    }
}
