#include <iomanip>
#include <iostream>
#include <sstream>
#include <vsomeip/vsomeip.hpp>
#include <vsomeip/constants.hpp>
#include <vsomeip/primitive_types.hpp>
#define IVEHICLES_SERVICE_ID 1335
#define IVEHICLES_INSTANCE_ID 22136
#define IVEHICLES_NOTIFIER_ID 3000
#define IVEHICLES_GETTER_ID 3001
#define IVEHICLES_SETTER_ID 3002

#define LOG(x) std::cout << #x << std::endl;

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
   LOG(ON SUBSCRIPTION);
   return true;
}


int main() {

   app = vsomeip::runtime::get()->create_application("fara_test_server");
   app->init();

   // Register handler for any of the possible incoming requests
   LOG(registering handler 1);
   app->register_message_handler(IVEHICLES_SERVICE_ID, IVEHICLES_INSTANCE_ID, IVEHICLES_NOTIFIER_ID /* (method id) */, on_message);
   LOG(registering handler 2);
   app->register_message_handler(IVEHICLES_SERVICE_ID, IVEHICLES_INSTANCE_ID, IVEHICLES_GETTER_ID /* (method id) */, on_message);
   LOG(registering handler 3);
   app->register_message_handler(IVEHICLES_SERVICE_ID, IVEHICLES_INSTANCE_ID, IVEHICLES_SETTER_ID /* (method id) */, on_message);

   // It's possible to request "ANY" also
   app->register_message_handler(vsomeip::ANY_SERVICE, vsomeip::ANY_INSTANCE, vsomeip::ANY_METHOD /* (method id) */, on_message);

   // ... but message_handler will only trigger for method calls?

   // ... let's try subscription handlder instead
   LOG(registering subscription handler);
   app->register_subscription_handler(IVEHICLES_SERVICE_ID, IVEHICLES_INSTANCE_ID, IVEHICLES_NOTIFIER_ID /* (event group?) */, on_subscription);

   LOG(offering service handler);

   app->offer_service(IVEHICLES_SERVICE_ID, IVEHICLES_INSTANCE_ID, 1,  0);
   app->start();
}
