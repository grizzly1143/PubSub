#ifndef PUBLSHERSUBSCRIBER_PUBLISHER_H
#define PUBLSHERSUBSCRIBER_PUBLISHER_H

#include <list>
#include "subscriber.h"

class Publisher {
public:
    explicit Publisher (const std::string& name) : pub_name(name) {}
    bool publish(const std::string& message);
    bool subsribe(Subscriber * sub);
    bool unsubscribe(Subscriber* const sub);
    void print_subs();
private:
    std::string pub_name;
    std::list<Subscriber*> subs_list;
};

#endif
