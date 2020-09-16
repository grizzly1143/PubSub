#include "subscriber.h"

bool Subscriber:: receive_event (const std::string& pub_name, const std::string& event_text) {
    if (pub_name.empty()) {
        return false;
    }
    if (event_text.empty()) {
        return false;
    }
    std:: cout << sub_name << " :: " << "Received publication from: " << pub_name << " with text: " << event_text << std::endl;
    return true;
}

std::string Subscriber::get_name() {
    return sub_name;
}
