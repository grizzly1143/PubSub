#ifndef PUBLSHERSUBSCRIBER_SUBSCRIBER_H
#define PUBLSHERSUBSCRIBER_SUBSCRIBER_H

#include <iostream>

class Subscriber {
public:
    Subscriber (const std::string& name);
    bool receive_event (const std::string& pub_name, const std::string& event_text);
    std::string get_name();
private:
    std::string sub_name;
};

#endif //PUBLSHERSUBSCRIBER_SUBSCRIBER_H
