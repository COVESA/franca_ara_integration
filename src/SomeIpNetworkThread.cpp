// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project

#include "SomeIpNetworkThread.h"
#include "imagesource.h"
#include "v1/genivi/aasr/showcase/IDrivingLaneProxy.hpp"
#include "v1/genivi/aasr/showcase/IVehiclesProxy.hpp"
#include "v1/genivi/aasr/showcase/IVehiclesSomeIPProxy.hpp"
#include <CommonAPI/AttributeCacheExtension.hpp>
#include <CommonAPI/CommonAPI.hpp>
#include <QQuickView>
#include <map>
#include <algorithm>
#include <set>

#define IMAGE_FEED_PATH                                                        \
   "/usr/local/share/franca-ara/images"

#define MAX_IMAGE_ID 228

#define LOG(x) std::cout << #x << std::endl;
#define MSLEEP(x)                                                              \
    std::this_thread::sleep_for(std::chrono::milliseconds((x)));

using v1::genivi::aasr::showcase::IVehiclesProxy;
using v1::genivi::aasr::showcase::IVehicles;
using v1::genivi::aasr::showcase::IDrivingLane;
using v1::genivi::aasr::showcase::IDrivingLaneProxy;

static int sanity_check_id (int id) {
   return std::max(0, std::min(id, MAX_IMAGE_ID));
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

    // We used to support multiple boxes.  Right now it's constant so the
    // color is constant too (and could just as well be handled in QML)
    b.color = "red";
    return b;
}

typedef std::pair<LaneLineDefinition, LaneLineDefinition> LaneDefinition_t;

static LaneDefinition_t get_bounding_lines(IDrivingLane::LaneType l)
{
    LaneLineDefinition left;
    left.lower_x = l.getLowerLeftPointX();
    left.lower_y = l.getLowerLeftPointY();
    left.upper_x = l.getIntersectionPointX();
    left.upper_y = l.getIntersectionPointY();

    LaneLineDefinition right;
    right.lower_x = l.getLowerRightPointX();
    right.lower_y = l.getLowerRightPointY();
    right.upper_x = l.getIntersectionPointX();
    right.upper_y = l.getIntersectionPointY();

    return LaneDefinition_t(left, right);
}

void SomeIpNetworkThread::connections(QQuickView &view)
{
    m_image_source.connectImageProvider(view);
}

void SomeIpNetworkThread::run()
{

    // Initial image to get started
    m_image_source.newFrameId(0);

    // (Note on style) Declaring this lambda expression inside of the member
    // function only because we need access to the m_image_source member
    // variable, and the closure this creates will make that possible.
    // There are surely a few other ways this could be done.
    auto vehicles_attribute_update = [&](const IVehicles::ListOfVehicles & v) {
        std::cerr << "Received change on Vehicles Attributes for frameId: " << v.getFrameId() << std::endl;

        int id = v.getFrameId();
        m_image_source.newFrameId(id);

        auto vehicle = v.getDetectedVehicle();
        auto bounding_box = v.getBox();

        int vehicle_id = sanity_check_id(vehicle.getId());
        BoxDefinition box_pod = get_pod_box(vehicle_id, bounding_box);

        // Delegate to image class to signal QML graphics to draw vehicle identification lines
        m_image_source.newVehicleIdentification(box_pod);
    };

    auto lane_broadcast_update = [&](const IDrivingLane::LaneType & l) {
        std::cerr << "Received change on Lane Attribute for frameId: " << l.getFrameId() << std::endl;

        int id = l.getFrameId();
        LaneDefinition_t lines = get_bounding_lines(l);

        // Delegate to image class to signal QML graphics to draw lane
        // identification lines
        m_image_source.newLaneIdentification(lines.first, lines.second);

        Q_UNUSED(id);  // FIXME
    };

    printf("Running: SomeIpNetworkThread\n");

    std::string domain = "local";
    std::string instance = "test"; // FIXME
    //   std::string connection = "mysomeipconnection";

    std::shared_ptr <CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();

    LOG(Build proxy in 1 seconds from now);
    MSLEEP(1000);

    //    auto vProxy = runtime->buildProxyWithDefaultAttributeExtension
    //        <IVehiclesProxy,CommonAPI::Extensions::AttributeCacheExtension>
    //        (domain, instance);
    //
    LOG(buildProxy);
    auto vProxy = runtime->buildProxy<IVehiclesProxy>(domain, instance);
    auto lProxy = runtime->buildProxy<IDrivingLaneProxy>(domain, instance);

    if (!vProxy) {
       LOG(Building vehicle i/f proxy failed!  Is NULL.  Stoppping);
       exit(1);
    }
    if (!lProxy) {
       LOG(Building lane i/f proxy failed!  Is NULL.  Stoppping);
       exit(1);
    }

    // This helps me understand what the hell is going on...
    LOG(Reminder : IVehicle Service ID = 1335 which is hex 0x537)
    LOG(Reminder : IVehicle Instance ID is 22136 which is hex 0x5678)

    LOG(waiting for proxy isAvailable);
    while (!vProxy->isAvailable()) {
        std::this_thread::sleep_for(std::chrono::microseconds(500000));
    }
    LOG(vehicle proxy is available !);
    while (!lProxy->isAvailable()) {
        std::this_thread::sleep_for(std::chrono::microseconds(500000));
    }
    LOG(lane proxy is available !);

    MSLEEP(3000);
    LOG(register callback);
    // Register callback function
    vProxy->getVehiclesAttribute().getChangedEvent().subscribe(vehicles_attribute_update);
    lProxy->getLaneDetectedEvent().subscribe(lane_broadcast_update);


    LOG(registered callback);

    while (true) {
        // Here the main loop.  Not sure how much needs to be done here
        // since a callback has been set up driven by the CommonAPI own
        // threads?

        LOG(MAIN LOOP);
        // Attributes are updated through callback above...
        // OK now what?
        int x = 0;
        ++x;
        MSLEEP(1000);

        // Try one output of lane signal
    static    auto x1 = new QLine(10,20,30,40);
    static            auto x2 = new QLine(10,20,30,40);

    m_image_source.laneIdentified(*x1,*x2);
    }
}

