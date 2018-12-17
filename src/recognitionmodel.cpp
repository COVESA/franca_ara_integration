// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project
#include "recognitionmodel.h"
#include <iostream>

#include <QQmlContext>
#include <QQmlEngine>

RecognitionModel::RecognitionModel(QObject *parent)
    : QObject(parent)
{
}

RecognitionModel::RecognitionModel(int id, const BoxDefinition &box,
                                   const LaneDefinition_t &lanes, QObject *parent)
    : QObject(parent), m_frame_id(id), m_box_valid(false), m_box(box), m_lanes(lanes)
{
}

BoxDefinition RecognitionModel::box() const
{
    return m_box;
}

void RecognitionModel::setBox(const BoxDefinition &box)
{
    m_box = box;
    m_box_valid = true;
    emit boxChanged();
}

void RecognitionModel::clearBox()
{
   m_box = BoxDefinition {0,0,0,0, false, ""};
   m_box_valid = false;
}

void RecognitionModel::setFrameId(int id)
{
    m_frame_id = id;
    //std::cerr << "setFrameId: " << m_frame_id << std::endl;
}

LaneDefinition_t RecognitionModel::lanes() const
{
    return m_lanes;
}

void RecognitionModel::newLaneIdentification(const LaneDefinition_t &lanes)
{
    m_lanes = lanes;
    emit laneChanged();
}

void RecognitionModel::connectRecognitionModel(QQuickView &view)
{
    view.engine()->rootContext()->setContextProperty("recognitionModel", this);

}
