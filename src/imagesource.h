#ifndef IMAGESOURCE_H
#define IMAGESOURCE_H

#include <QThread>
#include <QImage>

class ImageSource : public QThread
{
    Q_OBJECT

    void run() override;

Q_SIGNALS:
    void imageReady(const QImage &s);
    void vehicle_identified(QRect box);
    void lane_identified(QLine &leftLine, QLine &rightLine);
};

#endif
