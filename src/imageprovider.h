// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project

#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QImage>
#include <QObject>
#include <QPainter>

#include <qqmlengine.h>
#include <qquickimageprovider.h>

class ImageProvider : public QObject, public QQuickImageProvider
{
    Q_OBJECT
public:
    ImageProvider(QObject* parent = 0);
    ~ImageProvider();

    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);

public slots:
    void setImage(const QImage &img);

Q_SIGNALS:
    void updateGraphicsImage();

private:
    QImage m_image;
};

#endif
