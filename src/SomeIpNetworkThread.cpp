// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project

#include <CommonAPI/AttributeCacheExtension.hpp>
#include <CommonAPI/CommonAPI.hpp>
#include <QDebug>
#include <QElapsedTimer>
#include <QImageReader>
#include <map>
#include <math.h>
#include <set>
#include "imagesource.h"
#include "v1/genivi/aasr/showcase/IDrivingLaneProxy.hpp"
#include "v1/genivi/aasr/showcase/IVehiclesProxy.hpp"
#include "v1/genivi/aasr/showcase/IVehiclesSomeIPProxy.hpp"
#include "SomeIpNetworkThread.h"

#define IMAGE_FEED_PATH                                                        \
   "/home/user/devel/GENIVI/franca_ara_integration/src/feed"

#define MAX_IMAGE_ID 228

using v1::genivi::aasr::showcase::IVehiclesProxy;
using v1::genivi::aasr::showcase::IVehicles;

// Permanent / shared data  -- These should be made class member for cleaner look
static std::map<uint8_t, std::string /*color*/> known_bounding_box_ids;
static IVehicles::BoundingBoxes bounding_box_map;
static std::vector<IVehicles::Vehicle> vehicles;

static int sanity_check_id (int id) {
    return id; // FIXME
}

static std::string get_new_color() {
    return "Red";
}

// Assuming that identified vehicles might not always come in the same order
// Actually, to be clear a map is unordered anyway.
// To keep the same color on each we should consider remembering which IDs have been seen
// To be decided: Do this in C++ part (efficient data structures) or in QML (would normally handle the colors)
void identify_bounding_box(uint8_t id) {
    //
    if (known_bounding_box_ids.find(id) == known_bounding_box_ids.end()) {
        // Not found, i.e. new
        std::string color = get_new_color();
        std::cout << "New identified object (stored) : " << id << ", with color" << color << std::endl;
        known_bounding_box_ids.insert(std::make_pair(id, color));
    }
}

// Only call this after identify_bounding_box (when we know it exists in the map)
static std::string bounding_box_color(uint8_t id) {
    // assert (exists in map)
    return known_bounding_box_ids[id];
}

// Convert box to our own POD data type before passing it on.
// (this is a possibly unnecessary abstraction, but at least we add the
// color info, which was not given in the network protocol)
static BoxDefinition get_pod_box(uint8_t id, const IVehicles::BoundingBox &box)
{
    BoxDefinition b;
    b.height = box.getHeight();
    b.width = box.getWidth();
    b.x = box.getTopLeftX();
    b.y = box.getTopLeftY();
    b.color = bounding_box_color(id);
    return b;
}

typedef std::pair<LaneLineDefinition, LaneLineDefinition> LaneDefinition_t;

static LaneDefinition_t get_bounding_lines(void/*todo*/) {

    LaneLineDefinition left;
    // left.lower_x =
    // left.lower_y =
    // left.upper_x =
    // left.upper_y =

    LaneLineDefinition right;
    // right.lower_x =
    // right.lower_y =
    // right.upper_x =
    // right.upper_y =

    return LaneDefinition_t(left, right);
}

void SomeIpNetworkThread::run()
{
    // (Note on style) Declaring this lambda expression inside of the member
    // function only because we need access to the m_image_source member
    // variable, and the closure this creates will make that possible.
    // There are surely a few other ways this could be done.
    auto vehicles_attribute_update = [&](const IVehicles::ListOfVehicles & v) {
        std::cout << "Received change on Vehicles Attributes for frameId: " << v.getFrameId() << std::endl;

        int id = v.getFrameId();
        m_image_source.newFrameId(id);

        // TODO: Is this ^^ frame ID supposed to drive the playback rate?

        m_image_source.newFrameId(id);

        vehicles = v.getDetectedVehicles();
        bounding_box_map = v.getBoxes();
        std::string hash = v.getFrameHash();

        for (auto it : vehicles) {
            int vehicle_id = sanity_check_id(it.getId());

            // Look up vehicle in bounding box map
            auto it2 = bounding_box_map.find(vehicle_id);
            if (it2 != bounding_box_map.end()) {
                // Found!  map returns a pair, so look at the box which is
                // the second parameter
                IVehicles::BoundingBox box = it2->second;

                BoxDefinition box_pod = get_pod_box(vehicle_id, box);

                // Signal QML graphics to draw vehicle identifying lines
                m_image_source.newVehicleIdentification(box_pod);
            }
        }
        Q_UNUSED(id);
    };

    printf("Running: SomeIpNetworkThread\n");

    std::string domain = "local";
    std::string instance = "test"; // FIXME
    //   std::string connection = "mysomeipconnection";

    std::shared_ptr <CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();

    auto myProxy = runtime->buildProxyWithDefaultAttributeExtension
        <IVehiclesProxy,CommonAPI::Extensions::AttributeCacheExtension>
        (domain, instance);

//    while (!myProxy->isAvailable())
//        std::this_thread::sleep_for(std::chrono::microseconds(1000));
    while (!myProxy->isAvailable())
        std::this_thread::sleep_for(std::chrono::microseconds(1000));

    // Register callback function
    myProxy->getVehiclesAttribute().getChangedEvent().subscribe(vehicles_attribute_update);

    // Initial image to get started
    m_image_source.newFrameId(0);

    while (true) {
        // Here the main loop.  Not sure how much needs to be done here
        // since a callback has been set up driven by the CommonAPI own
        // threads?

        // Attributes are updated through callback above...
        // OK now what?
        int x = 0;
        ++x;
    }

    // TODO: On lane update:
    // Signal QML graphics to draw lane identifications
    LaneDefinition_t lines = get_bounding_lines(/*...*/);
    m_image_source.newLaneIdentification(lines.first, lines.second);
}

