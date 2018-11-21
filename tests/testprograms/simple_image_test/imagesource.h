#ifndef IMAGESOURCE_H
#define IMAGESOURCE_H

#include <QImage>
#include <QThread>

class ImageSource : public QThread
{
    Q_OBJECT

    void run() override;

  Q_SIGNALS:
    void imageReady(const QImage &s);
};

#endif
