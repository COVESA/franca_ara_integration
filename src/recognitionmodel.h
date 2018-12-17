// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project

#ifndef RECOGNITION_MODEL_H
#define RECOGNITION_MODEL_H

#include <QColor>
#include <QObject>
#include <QQuickView>

#include "SomeIpNetworkThreadTypes.h"

class RecognitionModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int boxX READ boxX NOTIFY boxChanged);
    Q_PROPERTY(int boxY READ boxY NOTIFY boxChanged);
    Q_PROPERTY(int boxH READ boxH NOTIFY boxChanged);
    Q_PROPERTY(int boxW READ boxW NOTIFY boxChanged);

    /* Box valid? (a.k.a. vehicle identified) */
//    Q_PROPERTY(int boxValid READ boxValid NOTIFY vehicleIdentified);

    Q_PROPERTY(QColor boxColor READ boxColor NOTIFY boxChanged);

    Q_PROPERTY(int laneLeftX1 READ laneLeftX1 NOTIFY laneChanged);
    Q_PROPERTY(int laneLeftX2 READ laneLeftX2 NOTIFY laneChanged);
    Q_PROPERTY(int laneLeftY1 READ laneLeftY1 NOTIFY laneChanged);
    Q_PROPERTY(int laneLeftY2 READ laneLeftY2 NOTIFY laneChanged);

    Q_PROPERTY(int laneRightX1 READ laneRightX1 NOTIFY laneChanged);
    Q_PROPERTY(int laneRightX2 READ laneRightX2 NOTIFY laneChanged);
    Q_PROPERTY(int laneRightY1 READ laneRightY1 NOTIFY laneChanged);
    Q_PROPERTY(int laneRightY2 READ laneRightY2 NOTIFY laneChanged);

public:
    RecognitionModel(QObject *parent=0);
    RecognitionModel(int id, const BoxDefinition &box,
                     const LaneDefinition_t &lanes,
                     QObject *parent=0);

    BoxDefinition box() const;
    void setBox(const BoxDefinition &name);
    void clearBox();

    int boxX() const { return m_box.x; };
    int boxY() const { return m_box.y; };
    int boxH() const { return m_box.height; };
    int boxW() const { return m_box.width; };
    int boxValid() const { return m_box_valid; };

    QColor boxColor() const { return QColor(m_box.color.c_str()); };

    int laneLeftX1() const { return m_lanes.first.lower_x; };
    int laneLeftX2() const { return m_lanes.first.upper_x; };
    int laneLeftY1() const { return m_lanes.first.lower_y; };
    int laneLeftY2() const { return m_lanes.first.upper_y; };

    int laneRightX1() const { return m_lanes.second.lower_x; };
    int laneRightX2() const { return m_lanes.second.upper_x; };
    int laneRightY1() const { return m_lanes.second.lower_y; };
    int laneRightY2() const { return m_lanes.second.upper_y; };

    LaneDefinition_t lanes() const;
    void newLaneIdentification(const LaneDefinition_t &lane);

    void connectRecognitionModel(QQuickView &view);

signals:
    void boxChanged();
    void laneChanged();
    void vehicleIdentified();

private:
    int m_id;
    BoxDefinition m_box;
    bool m_box_valid;
    LaneDefinition_t m_lanes;
};

#endif // RECOGNITION_MODEL_H
