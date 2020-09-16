#include "subscriber.h"

Subscriber::Subscriber (const std::string& name) : sub_name(name){
    last_recieved = "";
};

bool Subscriber:: receive_event (const std::string& pub_name, const std::string& event_text) {
    if (pub_name.empty()) {
        return false;
    }
    if (event_text.empty()) {
        return false;
    }
    last_recieved = event_text;
    std:: cout << sub_name << " :: " << "Received publication from: " << pub_name << " with text: " << event_text << std::endl;
    return true;
}

std::string Subscriber::get_last_message() {
    return last_recieved;
}

std::string Subscriber::get_name() {
    return sub_name;
}
