#include "imagesource.h"

void ImageSource::run()
 {
    while (true) {
        auto image = QImage(":/GENIVI_Black_Logo-white_background.jpg");
        emit imageReady(image);

        sleep(1);

        image = QImage(":/GENIVI_White_Logo-black_background.jpg");
        emit imageReady(image);

        sleep(1);
    }
}
