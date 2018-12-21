// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project

#ifndef IMAGESOURCE_H
#define IMAGESOURCE_H

#include <QThread>
#include <QImage>
#include <QQuickView>
#include "imageprovider.h"

#include "SomeIpNetworkThreadTypes.h"

// Types used in communication between image source class (C++)
// and the QML thread. (All other signals use primitive Qt types
// like QRect etc.)
typedef std::pair<QLine, QLine> Drawn_Lane_Boundary_t;

class ImageSource : public QObject
{
    Q_OBJECT

public:
    ImageSource();

    // Called from network class to initialize signals/slots etc
    void connectImageProvider(QQuickView &view);

    // These functions are called explicitly (they are not slots that can be
    // bound to any signal), from the network thread.  The functions take
    // "non-Qt" data and construct an appropriate Qt object and send it by
    // signal to the QML thread.
    void newFrameId(int frameID);
    void newVehicleIdentification();

Q_SIGNALS: // (Signals sent to QML graphics program)
    void imageReady(const QImage &s);
    void vehicleIdentified();
    void laneIdentified(QLine &leftLine, QLine &rightLine);

private:
    std::vector<QImage>  m_image_vector;
    ImageProvider _provider;
};

#endif
