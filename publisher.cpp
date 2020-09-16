#include "publisher.h"

bool Publisher::subsribe(Subscriber *sub) {
    if (sub == nullptr)
        return false;
    subs_list.push_back(sub);
}

bool Publisher::publish(const std::string &message) {
    if (message.empty()) {
        return false;
    }
    std::list<Subscriber*>::iterator p;
    for (p = subs_list.begin(); p != subs_list.end(); p++) {
        (*p)->receive_event(pub_name, message);
    }
    return true;
}

bool Publisher::unsubscribe(Subscriber * const sub) {
    if (sub == nullptr) {
        return false;
    }
    subs_list.remove(sub);
    return true;
}

void Publisher::print_subs() {
    std::list<Subscriber*>::iterator p;
    for (p = subs_list.begin(); p != subs_list.end(); p++) {
        std::cout << (*p)->get_name() << " ";
    }
    std::cout << std::endl;
}