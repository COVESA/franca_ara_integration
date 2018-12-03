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

#define IVEHICLES_SERVICE_ID 1335   /* = 0x537 */
#define IVEHICLES_INSTANCE_ID 22136
#define IVEHICLES_NOTIFIER_ID 3000
#define IVEHICLES_GETTER_ID 3001    /* = 0xBB9 */
#define IVEHICLES_SETTER_ID 3002    /* = 0xBBA */
#define EVENT_GROUP_ID 1

#define LOG(x) std::cerr << #x << std::endl;

std::shared_ptr<vsomeip::application> app;
void on_message(const std::shared_ptr<vsomeip::message> &_request)
{
    std::shared_ptr<vsomeip::payload> payload = _request->get_payload();

    LOG(ON MESSAGE);
    auto len = payload->get_length();

    std::stringstream ss;
    for (auto i = 0; i < len; i++) {
        ss << std::setw(2) << std::setfill('0') << std::hex
           << (int)*(payload->get_data() + i) << " ";
    }

    std::cout << "SERVICE: Received message with Client/Session ["
        << std::setw(4) << std::setfill('0') << std::hex << _request->get_client() << "/"
        << std::setw(4) << std::setfill('0') << std::hex << _request->get_session() << "] "
        << ss.str() << std::endl;

    // Create response
    std::shared_ptr<vsomeip::message> response = vsomeip::runtime::get()->create_response(_request);
    payload = vsomeip::runtime::get()->create_payload();
    std::vector<vsomeip::byte_t> data;
    for (int i=9; i>=0; i--) {
        data.push_back(i % 256);
    }

    payload->set_data(data);
    response->set_payload(payload);
    app->send(response, true);
}

bool on_subscription(vsomeip::client_t c, bool isSubscribed) {
   LOG(Someone changed subscription on event group);
   return true;
}

int run() {
   static vsomeip::byte_t data[] = { /* FIXME sizeof vehicle struct */ 0xAA };

   std::shared_ptr<vsomeip::payload> payload;
   payload = vsomeip::runtime::get()->create_payload();

   int i;
   // Just a loop to make the data change
   for (i = 0 ; i < 1000000 ; ++i) {
      data[0] = i;
      payload->set_data(data, sizeof(data)); // junk data so far
      LOG(Test Server: Notifying event IVEHICLES_NOTIFIER_ID);
      app->notify(IVEHICLES_SERVICE_ID, IVEHICLES_INSTANCE_ID, IVEHICLES_NOTIFIER_ID, payload);
      std::this_thread::sleep_for(std::chrono::seconds(4));
   }
}

int main() {

   app = vsomeip::runtime::get()->create_application("fara_test_server");
   app->init();

   // Register handler for any of the possible incoming requests
   // It's possible to request "ANY" also
   LOG(registering message handler);
//   app->register_message_handler(IVEHICLES_SERVICE_ID, vsomeip::ANY_INSTANCE, vsomeip::ANY_METHOD /* (method id) */, on_message);
//   app->register_message_handler(IVEHICLES_SERVICE_ID, vsomeip::ANY_INSTANCE, vsomeip::ANY_EVENT /* (method id) */, on_message);

   // ... but we're not expecting messages.  Check subscription status instead
//   LOG(registering subscription handler);
//   app->register_subscription_handler(IVEHICLES_SERVICE_ID, IVEHICLES_INSTANCE_ID, EVENT_GROUP_ID, on_subscription);

   LOG(offering service handler);
   app->offer_service(IVEHICLES_SERVICE_ID, IVEHICLES_INSTANCE_ID, 1 /*major version*/ ,  0 /*minor version*/ );

   std::set<vsomeip::eventgroup_t> groups;
   groups.insert(EVENT_GROUP_ID);
   app->offer_event(IVEHICLES_SERVICE_ID, IVEHICLES_INSTANCE_ID, IVEHICLES_NOTIFIER_ID, groups, true);

   // Send an update
   const vsomeip::byte_t data[] = { /* FIXME sizeof vehicle struct */ 0xAA, 0xBB, 0xCC } ;

   std::thread notifier(run);

   app->start();
}

