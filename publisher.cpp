#include "publisher.h"

Publisher::Publisher(std::string name) : pub_name(std::move(name)) {}

bool Publisher::subsribe(const std::shared_ptr<Subscriber>& sub) {
    if (sub == nullptr)
        return false;
    subs_list.push_back(sub);
    return true;
}

bool Publisher::publish(const std::string &message) {
    if (message.empty()) {
        return false;
    }
    if (subs_list.empty()) {
        return false;
    }
    for (const auto &p : subs_list) {
        p->receive_event(pub_name, message);
    }
    return true;
}

bool Publisher::unsubscribe(const std::shared_ptr<Subscriber>& sub) {
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
