// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project
//
#ifndef SOMEIPNETWORKTHREADTYPES
#define SOMEIPNETWORKTHREADTYPES

#include <string>

// POD datatypes used only between networking & graphics classes
struct BoxDefinition {
    int x, y, width, height;
    std::string color;
};

struct LaneLineDefinition {
   int lower_x,
       lower_y,
       upper_x,
       upper_y;
};

#endif
