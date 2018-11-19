#ifndef IMAGESOURCE_H
#define IMAGESOURCE_H

#include <QThread>
#include <QImage>
#include "SomeIpNetworkThreadTypes.h"

// Types used in communication between image source class (C++)
// and the QML thread. (All other signals use primitive Qt types
// like QRect etc.)
typedef std::pair<QLine, QLine> Drawn_Lane_Boundary_t;

class ImageSource : public QObject
{
    Q_OBJECT

// These functions are called explicitly (they are not slots that can be
// bound to any signal), from the network thread.  The functions take
// "non-Qt" data and construct an appropriate Qt object and send it by
// signal to the QML thread.
public:
    void newFrameId(int frameID);
    void newVehicleIdentification (const BoxDefinition &box);
    void newLaneIdentification (const LaneLineDefinition &left, const LaneLineDefinition &right);

Q_SIGNALS:
    void imageReady(const QImage &s);
    void vehicle_identified(QRect box);
    void lane_identified(QLine &leftLine, QLine &rightLine);
};

#endif
