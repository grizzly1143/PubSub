#ifndef PUBLSHERSUBSCRIBER_SUBSCRIBER_H
#define PUBLSHERSUBSCRIBER_SUBSCRIBER_H

#include <iostream>

class Subscriber {
public:
    Subscriber (const std::string& name);
    void receive_event (const std::string& event_text);
private:
    std::string sub_name;
};

#endif //PUBLSHERSUBSCRIBER_SUBSCRIBER_H
