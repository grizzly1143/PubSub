#ifndef PUBLSHERSUBSCRIBER_PUBLISHER_H
#define PUBLSHERSUBSCRIBER_PUBLISHER_H

#include <list>
#include "subscriber.h"

class Publisher {
public:
    Publisher (const std::string& name);
    void publish(const std::string& message);
    bool subsribe(const Subscriber * sub);
    bool unsubscribe(const Subscriber* sub);
private:
    std::string pub_name;
    std::list<Subscriber*> subs;
};

#endif
