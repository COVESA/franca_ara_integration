// SPDX-License-Identifier: MPL-2.0

// (C) 2018 GENIVI Alliance
// This file is part of FRANCA--ARA integration demo/pilot project

#include <iomanip>
#include <iostream>

#include <vsomeip/vsomeip.hpp>
#include <vsomeip/constants.hpp>
#include <vsomeip/primitive_types.hpp>

#define IVEHICLES_SERVICE_ID 1335
#define IVEHICLES_INSTANCE_ID 22136
#define IVEHICLES_NOTIFIER_ID 3000
#define IVEHICLES_GETTER_ID 3001
#define IVEHICLES_SETTER_ID 3002

// Simple vSomeIP-only client (no CommonAPI) which can request the service
// and report if it is running

void on_availability(vsomeip::service_t s, vsomeip::instance_t inst, bool state) {
    std::cout << "Service [" << std::setw(4) << s << '(' << std::setfill('0') << std::hex << s << ')' << "." << inst << "] " << (state ? "became available." : "is no longer available.")  << std::endl;
}

int main() {
   std::shared_ptr< vsomeip::application > app;
   app = vsomeip::runtime::get()->create_application("Plain vsomeip client");
   app->init();
   app->register_availability_handler(IVEHICLES_SERVICE_ID, IVEHICLES_INSTANCE_ID, on_availability);
   app->request_service(IVEHICLES_SERVICE_ID, IVEHICLES_INSTANCE_ID);
   app->start();
}
