// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project


#include "v1/genivi/aasr/showcase/IDrivingLaneProxy.hpp"
#include "v1/genivi/aasr/showcase/IVehiclesProxy.hpp"
#include "v1/genivi/aasr/showcase/IVehiclesSomeIPProxy.hpp"
#include <CommonAPI/AttributeCacheExtension.hpp>
#include <CommonAPI/CommonAPI.hpp>

#define LOG(x) std::cerr << #x << std::endl;
#define MSLEEP(x)                                                              \
    std::this_thread::sleep_for(std::chrono::milliseconds((x)));

using v1::genivi::aasr::showcase::IVehiclesProxy;
using v1::genivi::aasr::showcase::IVehicles;
using v1::genivi::aasr::showcase::IDrivingLane;
using v1::genivi::aasr::showcase::IDrivingLaneProxy;

static void vehicles_attribute_update(const v1::genivi::aasr::showcase::IVehicles::ListOfVehicles &v) {

   std::cerr << "Received change on Vehicles Attributes for frameId: " << v.getFrameId() << std::endl;
   auto vehicle = v.getDetectedVehicle();
   auto id = vehicle.getId();
   if (id != 0) {
      std::cerr << "detectedVehicle.id = " << (int)id << std::endl;
      std::cerr << "               .currentDistance(float) = " << vehicle.getCurrentDistance().getFloatingPoint().getFloatingPoint32Bit() << std::endl;
      std::cerr << "               .currentDistance(double) = " << vehicle.getCurrentDistance().getFloatingPoint().getFloatingPoint64Bit() << std::endl;
      auto box = v.getBox();
      std::cerr << "box.topLeftX = " << box.getTopLeftX() << std::endl;
      std::cerr << "box.topLeftY = " << box.getTopLeftY() << std::endl;
      std::cerr << "box.width = " << box.getWidth() << std::endl;
      std::cerr << "box.height = " << box.getHeight() << std::endl;
   } else {
      std::cerr << "No identified vehicle" << std::endl;
   }
}

static void lane_broadcast_update(const v1::genivi::aasr::showcase::IDrivingLane::LaneType &lane) {

   std::cerr << "Received change on Lane Attributes for frameId:" << lane.getFrameId() << std::endl;
   std::cerr << "lane.lowerLeftPointX = " << lane.getLowerLeftPointX() << std::endl;
   std::cerr << "    .lowerLeftPointY = " << lane.getLowerLeftPointY() << std::endl;
   std::cerr << "    .lowerRightPointX = " << lane.getLowerRightPointX() << std::endl;
   std::cerr << "    .intersectionPointX = " << lane.getIntersectionPointX() << std::endl;
   std::cerr << "    .intersectionPointY = " << lane.getIntersectionPointY() << std::endl;
}

int main(int argc, char *argv[])
{
   CommonAPI::Runtime::setProperty("LogContext", "FARA");
   CommonAPI::Runtime::setProperty("LogApplication", "FARA");

   std::string domain = "local";
   std::string instance = "test";
   std::string lane_instance = "drivinglane";
//   std::string connection = "mysomeipconnection";

   std::shared_ptr <CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();

   if (!runtime) {
      std::cerr << "Runtime is NULL.  Giving up" << std::endl;
      exit(1);
   }

   LOG(Build proxy in 1 seconds from now);
   MSLEEP(1000);

   LOG(buildProxy);
   auto laneProxy = runtime->buildProxy<IDrivingLaneProxy>(domain, lane_instance);
   if (!laneProxy) {
      LOG(Building lane proxy failed!  Is NULL.  Stoppping);
      exit(1);
   }
   auto myProxy = runtime->buildProxy<IVehiclesProxy>(domain, instance);
   if (!myProxy) {
      LOG(Building proxy failed!  Is NULL.  Stoppping);
      exit(1);
   }

   // This helps me understand what the hell is going on...
   LOG(Reminder : IVehicle Service ID = 1335 which is hex 0x537);
   LOG(Reminder : IVehicle Instance ID is 22136 which is hex 0x5678);

   LOG(waiting for proxy isAvailable);
   while (!myProxy->isAvailable()) {
      MSLEEP(500);
   }
   while (!laneProxy->isAvailable()) {
      MSLEEP(500);
   }
   LOG(proxy is available !);

   MSLEEP(2000);

   LOG(register callback);
   myProxy->getVehiclesAttribute().getChangedEvent().subscribe(&vehicles_attribute_update);

   // FIXME
   laneProxy->getLaneDetectedEvent().subscribe(&lane_broadcast_update);

   LOG(registered callback);

   while (true) {
      // Not much happening here
      LOG(Main loop is alive);
      MSLEEP(5000);
   }
}

