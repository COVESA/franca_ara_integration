// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project


#include "v1/genivi/testexec/IVehiclesProxy.hpp"
#include "v1/genivi/testexec/IVehiclesSomeIPProxy.hpp"
#include <CommonAPI/AttributeCacheExtension.hpp>
#include <CommonAPI/CommonAPI.hpp>

#define LOG(x) std::cerr << #x << std::endl;
#define MSLEEP(x)                                                              \
    std::this_thread::sleep_for(std::chrono::milliseconds((x)));

using v1::genivi::testexec::IVehiclesProxy;
using v1::genivi::testexec::IVehicles;

static void vehicles_attribute_update(const v1::genivi::testexec::IVehicles::ListOfVehicles &v) {
   //std::cerr << "Received change on Vehicles Attributes for frameId: " << v.getFrameId() << std::endl;
   std::cerr << "Received change on Vehicles Attributes " << std::endl;
}

int main(int argc, char *argv[])
{
   std::string domain = "local";
   std::string instance = "test";
   std::string connection = "mysomeipconnection";

   std::shared_ptr <CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();

   std::cerr << "Size of ListOfVehicles is " << sizeof(IVehicles::ListOfVehicles) << std::endl;

   LOG(Build proxy in 1 seconds from now);
   MSLEEP(1000);

   LOG(buildProxy);
   auto myProxy = runtime->buildProxy<IVehiclesProxy>(domain, instance);

   if (!myProxy) {
      LOG(Building proxy failed!  Is NULL.  Stoppping);
      exit(0);
   }

   // This helps me understand what the hell is going on...
   LOG(Reminder : IVehicle Service ID = 1335 which is hex 0x537);
   LOG(Reminder : IVehicle Instance ID is 22136 which is hex 0x5678);

   LOG(waiting for proxy isAvailable);
   while (!myProxy->isAvailable()) {
      MSLEEP(500);
   }
   LOG(proxy is available !);

   MSLEEP(2000);

   LOG(register callback);
   myProxy->getVehiclesAttribute().getChangedEvent().subscribe(&vehicles_attribute_update);
   LOG(registered callback);

   while (true) {
      // Not much happening here
      LOG(Main loop is alive);
      MSLEEP(5000);
   }
}

