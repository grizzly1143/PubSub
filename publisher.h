#ifndef PUBLSHERSUBSCRIBER_PUBLISHER_H
#define PUBLSHERSUBSCRIBER_PUBLISHER_H

#include <list>
#include <memory>
#include "subscriber.h"

class Publisher {
public:
    Publisher (const std::string& name);
    bool publish(const std::string& message);
    bool subsribe(std::shared_ptr<Subscriber> sub);
    bool unsubscribe(std::shared_ptr<Subscriber> sub);
    void print_subs();
private:
    std::string pub_name;
    std::list<std::shared_ptr<Subscriber>> subs_list;
};

#endif
