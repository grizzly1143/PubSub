#ifndef PUBLSHERSUBSCRIBER_PUBLISHER_H
#define PUBLSHERSUBSCRIBER_PUBLISHER_H

#include <list>
#include <memory>
#include "subscriber.h"

class Publisher {
public:
    Publisher(std::string name);
    bool publish(const std::string& message);
    bool subsribe(const std::shared_ptr<Subscriber>& sub);
    bool unsubscribe(const std::shared_ptr<Subscriber>& sub);
    void print_subs();
private:
    std::string pub_name;
    std::list<std::shared_ptr<Subscriber>> subs_list;
};

#endif
