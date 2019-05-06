// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project

#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "v1/genivi/aasr/showcase/IVehiclesStubDefault.hpp"
#include "v1/genivi/aasr/showcase/IDrivingLaneStubDefault.hpp"

#include "conf/datatable.h"


#define LOG(x) std::cerr << #x << std::endl;
#define MSLEEP(x)                                                              \
    std::this_thread::sleep_for(std::chrono::milliseconds((x)));
#define MAX_IMAGE_ID 228

using v1::genivi::aasr::showcase::IVehicles;
using v1::genivi::aasr::showcase::IVehiclesStubDefault;
using v1::genivi::aasr::showcase::IDrivingLane;
using v1::genivi::aasr::showcase::IDrivingLaneStubDefault;

int main() {
   CommonAPI::Runtime::setProperty("LogContext", "FARA");
   CommonAPI::Runtime::setProperty("LogApplication", "FARA");

   std::shared_ptr <CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();

   if (!runtime) {
      std::cerr << "Runtime is NULL.  Giving up" << std::endl;
      exit(1);
   }

   std::string domain = "local";
   std::string instance = "test";
   std::string lane_instance = "drivinglane";
   // std::string connection = "mysomeipconnection";

   std::shared_ptr<IVehiclesStubDefault> vService = std::make_shared<IVehiclesStubDefault>();
   while (!runtime->registerService(domain, instance, vService /*, connection*/)) {
      std::cout << "Register Vehicle Service failed, trying again in 2 seconds..." << std::endl;
      MSLEEP(2000);
   }

   std::shared_ptr<IDrivingLaneStubDefault> lService = std::make_shared<IDrivingLaneStubDefault>();
   while (!runtime->registerService(domain, lane_instance, lService /*, connection*/)) {
      std::cout << "Register Lane Service failed, trying again in 2 seconds..." << std::endl;
      MSLEEP(2000);
   }

   std::cout << "Successfully Registered Service!" << std::endl;

   // The attribute that is being tested, updated inside loop
   IVehicles::ListOfVehicles list_of_vehicles;
   IVehicles::BoundingBox bounding_box;

   static int direction = -1;
   while (true) {
      direction = -direction;
      int i;
      for (i = 0 ; i <= MAX_IMAGE_ID ; ++i) {

         LOG(capi_server: Main loop is alive);

         IVehicles::BoundingBox box;

         // Bounding box: Fetching data from predefined table, driven by
         // the i counter
         box.setTopLeftX(VehicleDetected_data[i].BoxTopLeftX);
         box.setTopLeftY(VehicleDetected_data[i].BoxTopLeftY);
         box.setWidth(VehicleDetected_data[i].BoxWidth);
         box.setHeight(VehicleDetected_data[i].BoxHeight);

         // Vehicle ID: Just set a valid (random) vehicle ID *if* there is
         // a non-zero bounding box defined
         IVehicles::Vehicle v;
         if (box.getTopLeftX() != 0) {
            v.setId(i);  // Valid ID for vehicle
         }
         else
         {
            v.setId(0); // Invalid (no vehicle)
         }

         // Distance and Collision:  Just sending dummy data
         IVehicles::FlexibleFloatingPointContainer fpc;
         IVehicles::FlexibleFloatingPoint value_s;
         float f = 0.44;
         value_s.setFloatingPoint32Bit(f);
         value_s.setFloatingPoint64Bit((double)f);
         fpc.setFloatingPoint(value_s);
         v.setCurrentDistance(fpc);
         v.setCollisionTime(fpc);

         list_of_vehicles.setFrameId(i);
         list_of_vehicles.setDetectedVehicle(v);
         list_of_vehicles.setBox(box);

         std::cerr << "capi_server: update, frameid i = " << i << " id = " << v.getId() << std::endl;
         vService->setVehiclesAttribute(list_of_vehicles);

         IDrivingLane::LaneType l;
         l.setFrameId(i);

         // Lanes: Fetching data from predefined table, driven by the i
         // counter
         l.setLowerLeftPointX(LaneDetected_data[i].LeftX);
         l.setLowerLeftPointY(LaneDetected_data[i].LeftY);
         l.setLowerRightPointX(LaneDetected_data[i].RightX);
         l.setLowerRightPointY(LaneDetected_data[i].RightY);
         l.setIntersectionPointX(LaneDetected_data[i].IntersectionX);
         l.setIntersectionPointY(LaneDetected_data[i].IntersectionY);

         lService->fireLaneDetectedEvent(l);

         MSLEEP(50);
      }
   }
   return 0;
}
