#include "subscriber.h"

Subscriber::Subscriber(const std::string &name){};
void Subscriber:: receive_event (const std::string& pub_name, const std::string& event_text) {
    std:: cout << "Received publication from: " << pub_name << " with text: " << event_text << std::endl;
}
