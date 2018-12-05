// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project

#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include "v1/genivi/testexec/IVehiclesStubDefault.hpp"

#define LOG(x) std::cerr << #x << std::endl;
#define MSLEEP(x)                                                              \
    std::this_thread::sleep_for(std::chrono::milliseconds((x)));

using v1::genivi::testexec::IVehicles;
using namespace v1::genivi::testexec;
using namespace std;

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
   // std::string connection = "mysomeipconnection";

   std::shared_ptr<IVehiclesStubDefault> myService = std::make_shared<IVehiclesStubDefault>();
   while (!runtime->registerService(domain, instance, myService /*, connection*/)) {
      std::cout << "Register Service failed, trying again in 2 seconds..." << std::endl;
      MSLEEP(2000);
   }

   std::cout << "Successfully Registered Service!" << std::endl;

   // The attribute that is being tested, updated inside loop
   v1::genivi::testexec::IVehicles::ListOfVehicles list_of_vehicles;

   while (true) {
      static int i = 0;

      LOG(simple_capi_server: Main loop is alive);

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
      IVehicles::Int_to_Int_Map tmp;
      tmp.insert(make_pair(i,0x10+i));
      tmp.insert(make_pair(i+1,0x20+i+1));
      ++i;

      list_of_vehicles.setThemap(tmp);

      LOG(simple_capi_server: Setting new list_of_vehicles value);
      myService->setVehiclesAttribute(list_of_vehicles);

      MSLEEP(5000);
   }
   return 0;
}
