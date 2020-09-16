#ifndef PUBLSHERSUBSCRIBER_SUBSCRIBER_H
#define PUBLSHERSUBSCRIBER_SUBSCRIBER_H

#include <iostream>

class Subscriber {
public:
    Subscriber (const std::string& name);
    bool receive_event (const std::string& pub_name, const std::string& event_text);
    std::string get_name();
    std::string get_last_message();
private:
    std::string sub_name;
    std::string last_recieved;
};

#endif //PUBLSHERSUBSCRIBER_SUBSCRIBER_H
