// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project

#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "v1/genivi/aasr/showcase/IVehiclesStubDefault.hpp"
#include "v1/genivi/aasr/showcase/IDrivingLaneStubDefault.hpp"
#include <algorithm>

#define LOG(x) std::cerr << #x << std::endl;
#define MSLEEP(x)                                                              \
    std::this_thread::sleep_for(std::chrono::milliseconds((x)));

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


/*	
	// Type definition of a lane
	struct LaneType {
		UInt16 frameId
		UInt32 lowerLeftPointX
		UInt32 lowerLeftPointY
		UInt32 lowerRightPointX
		UInt32 lowerRightPointY
		UInt32 intersectionPointX
		UInt32 intersectionPointY
	}

	// Messages --------------------------------------------

	// Event-based communication of the detected lane
	broadcast LaneDetected {
		out {
			LaneType drivingLane
		}	
	}
}
*/
	
   static int i = 0;
   static int direction = 1;
   while (true) {

      LOG(capi_server: Main loop is alive);

      // Update value

      // Example of available setters:
      //        inline void setFrameId(const uint16_t &_value) { std::get< 0>(values_) = _value; }
      //        inline void setOneVehicle(const Vehicle &_value) { std::get< 1>(values_) = _value; }
      //        inline void setTwoVehicle(const Vehicle &_value) { std::get< 2>(values_) = _value; }
      //        inline void setFrameHash(const std::string &_value) { std::get< 3>(values_) = _value; }

      // Change some value
//      list_of_vehicles.setFrameId(i++);

      // typedef std::unordered_map< uint8_t, uint16_t> Int_to_Int_Map;
      //inline void setThemap(const Int_to_Int_Map &_value) { std::get< 1>(values_) = _value; }
      IVehicles::BoundingBox box;
      box.setTopLeftX(i);
      box.setTopLeftY(i+20);
      box.setWidth(i+40);
      box.setHeight(i+60);

      IVehicles::Vehicle v;
      v.setId(0);
      IVehicles::FlexibleFloatingPointContainer fpc;
      IVehicles::FlexibleFloatingPoint value_s;
      float f = 0.44;
      value_s.setFloatingPoint32Bit(f);
      value_s.setFloatingPoint64Bit((double)f);
      fpc.setFloatingPoint(value_s);
      v.setCurrentDistance(fpc);
      v.setCollisionTime(fpc);

      i = i + direction;
      list_of_vehicles.setFrameId(i);
      list_of_vehicles.setDetectedVehicle(v);
      list_of_vehicles.setBox(box);

      LOG(capi_server: Setting new list_of_vehicles value);
      vService->setVehiclesAttribute(list_of_vehicles);

      IDrivingLane::LaneType l;
      l.setFrameId(i);
      l.setLowerLeftPointX(50+i);
      l.setLowerLeftPointY(700);
      l.setLowerRightPointX(900-i);
      l.setLowerRightPointY(700);
      l.setIntersectionPointX(350);
      l.setIntersectionPointY(50);
      if (i == 0)
         direction = 1;
      if (i == 200)
         direction = -1;

      // TODO: How to set broadcast data and notify
      LOG(capi_server: Broadcasting lane event);
      lService->fireLaneDetectedEvent(l);

      MSLEEP(50);
   }
   return 0;
}
