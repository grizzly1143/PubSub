#include "publisher.h"

Publisher::Publisher (const std::string& name) : pub_name(name) {}

bool Publisher::subsribe(std::shared_ptr<Subscriber> sub) {
    if (sub == nullptr)
        return false;
    subs_list.push_back(sub);
}

bool Publisher::publish(const std::string &message) {
    if (message.empty()) {
        return false;
    }
    for (const auto &p : subs_list) {
        p->receive_event(pub_name, message);
    }
    return true;
}

bool Publisher::unsubscribe(std::shared_ptr<Subscriber> sub) {
    if (sub == nullptr) {
        return false;
    }
    subs_list.remove(sub);
    return true;
}

void Publisher::print_subs() {
    for (const auto &p : subs_list) {
        std::cout << p->get_name() << " ";
    }
    std::cout << std::endl;
}