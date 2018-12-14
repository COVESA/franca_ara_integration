// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project

#ifndef RECOGNITION_MODEL_H
#define RECOGNITION_MODEL_H

#include <QObject>
#include <QColor>

#include "SomeIpNetworkThreadTypes.h"

class RecognitionModel : public QObject
{
    Q_OBJECT

    //Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
  //  Q_PROPERTY(BoxDefinition box READ box WRITE setBox NOTIFY boxChanged)
    Q_PROPERTY(LaneDefinition_t lanes READ lanes NOTIFY lanesChanged)

    Q_PROPERTY(int boxX READ boxX NOTIFY boxChanged);
    Q_PROPERTY(int boxY READ boxY NOTIFY boxChanged);
    Q_PROPERTY(int boxH READ boxH NOTIFY boxChanged);
    Q_PROPERTY(int boxW READ boxW NOTIFY boxChanged);
    Q_PROPERTY(QColor boxColor READ boxColor NOTIFY boxChanged);

public:
    RecognitionModel(QObject *parent=0);
    RecognitionModel(int id, const BoxDefinition &box,
                     const LaneDefinition_t &lanes,
                     QObject *parent=0);

    BoxDefinition box() const;
    void setBox(const BoxDefinition &name);

    int boxX() const {return m_box.x; }
    int boxY() const {return m_box.y; };
    int boxH() const {return m_box.height; };
    int boxW() const {return m_box.width; };
    QColor boxColor() const {return QColor(m_box.color.c_str()); };

    LaneDefinition_t lanes() const;
    void newLaneIdentification(const LaneDefinition_t &color);

//    int id() const;
//    void setId(const int &id);

signals:
    void boxChanged();
    void lanesChanged();
    void idChanged();

private:
    int m_id;
    BoxDefinition m_box;
    LaneDefinition_t m_lanes;
};

#endif // RECOGNITION_MODEL_H
