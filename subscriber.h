#ifndef PUBLSHERSUBSCRIBER_SUBSCRIBER_H
#define PUBLSHERSUBSCRIBER_SUBSCRIBER_H

#include <iostream>

class Subscriber {
public:
    explicit Subscriber (const std::string& name) : sub_name(name){};
    bool receive_event (const std::string& pub_name, const std::string& event_text);
    std::string get_name();
private:
    std::string sub_name;
};

#endif //PUBLSHERSUBSCRIBER_SUBSCRIBER_H
