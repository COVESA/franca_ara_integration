// SPDX-License-Identifier: MPL-2.0

// Copyright (C) 2018 GENIVI Alliance
// Copyright (C) 2015 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// (parts derived from CommonAPI example code)
// This file is part of FRANCA--ARA integration demo/pilot project

#include <iomanip>
#include <iostream>
#include <sstream>
#include <thread>

#include <vsomeip/vsomeip.hpp>
#include <vsomeip/constants.hpp>
#include <vsomeip/primitive_types.hpp>
#include <vsomeip/enumeration_types.hpp>

#define IVEHICLES_SERVICE_ID 1335
#define IVEHICLES_INSTANCE_ID 22136
#define IVEHICLES_NOTIFIER_ID 3000
#define IVEHICLES_GETTER_ID 3001
#define IVEHICLES_SETTER_ID 3002
#define EVENT_GROUP_ID 1

#define LOG(x) std::cerr << #x << std::endl;

// Simple vSomeIP-only client (no CommonAPI) which can request the service
// and report if it is running

static std::shared_ptr< vsomeip::application > app;
void on_availability(vsomeip::service_t s, vsomeip::instance_t inst, bool state) {
    std::cerr << "Service [" << std::setw(4) << s << '(' << std::setfill('0') << std::hex << s << ')' << "." << inst << "] " << (state ? "became available." : "is no longer available.")  << std::endl;
}

void on_message(const std::shared_ptr<vsomeip::message> &_response) {

   std::shared_ptr<vsomeip::payload> payload = _response->get_payload();
   vsomeip::length_t l = payload->get_length();

  // Get payload
  std::stringstream ss;
  for (vsomeip::length_t i=0; i<l; i++) {
     ss << std::setw(2) << std::setfill('0') << std::hex
        << (int)*(payload->get_data()+i) << " ";
  }

  std::cerr << "Test Client: Received message with Client/Session ["
      << std::setw(4) << std::setfill('0') << std::hex << _response->get_client() << "/"
      << std::setw(4) << std::setfill('0') << std::hex << _response->get_session() << "] "
      << ss.str() << std::endl;
}

int run() {
   // Quick and dirty, make sure the rest has started
   std::this_thread::sleep_for(std::chrono::seconds(1));

   std::cerr << "Starting test client handler thread" << std::endl;
   std::set<vsomeip::eventgroup_t> groups;
   groups.insert(EVENT_GROUP_ID);
   std::cerr << "Test Client: Request event " << std::endl;
   app->request_event(IVEHICLES_SERVICE_ID, IVEHICLES_INSTANCE_ID, IVEHICLES_NOTIFIER_ID, groups, true);
   std::cerr << "Test Client: Subscribing" << std::endl;
   app->subscribe(IVEHICLES_SERVICE_ID, IVEHICLES_INSTANCE_ID, EVENT_GROUP_ID, 1 /*Major version*/);
   std::cerr << "Test Client: Done Subscribing" << std::endl;
   std::this_thread::sleep_for(std::chrono::seconds(20000));
}

int main() {
   app = vsomeip::runtime::get()->create_application("fara test client");

   app->init();
   app->register_availability_handler(IVEHICLES_SERVICE_ID, IVEHICLES_INSTANCE_ID, on_availability);
   app->request_service(IVEHICLES_SERVICE_ID, IVEHICLES_INSTANCE_ID, 1 /*major version*/, 0/*minor version*/);
   app->register_message_handler(IVEHICLES_SERVICE_ID, IVEHICLES_INSTANCE_ID, IVEHICLES_NOTIFIER_ID, on_message);

   std::thread sender(run);
   LOG(App start);
   app->start();
}
