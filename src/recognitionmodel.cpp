// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project
#include "recognitionmodel.h"

RecognitionModel::RecognitionModel(QObject *parent)
    : QObject(parent)
{
}

RecognitionModel::RecognitionModel(int id, const BoxDefinition &box,
    const LaneDefinition_t &lanes, QObject *parent)
    : QObject(parent), m_id(id), m_box(box), m_lanes(lanes)
{
}

int RecognitionModel::id() const
{
    return m_id;
}

void RecognitionModel::setId(const int &id)
{
        m_id = id;
        emit idChanged();
}

BoxDefinition RecognitionModel::box() const
{
    return m_box;
}

void RecognitionModel::setBox(const BoxDefinition &box)
{
        m_box = box;
        emit boxChanged();
}

LaneDefinition_t RecognitionModel::lanes() const
{
    return m_lanes;
}

void RecognitionModel::setLanes(const LaneDefinition_t &lanes)
{
        m_lanes = lanes;
        emit lanesChanged();
}
