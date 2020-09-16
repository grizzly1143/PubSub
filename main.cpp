#include "publisher.h"
#include "subscriber.h"

int main() {
    Publisher pub("Pub1");
    std::shared_ptr<Subscriber> sub1 = std::make_shared<Subscriber>("Sub1");
    pub.subsribe(sub1);
    std::shared_ptr<Subscriber> sub2 = std::make_shared<Subscriber>("Sub2");
    pub.subsribe(sub2);
    pub.print_subs();
    pub.publish("Test publication");
    pub.unsubscribe(sub2);
    pub.print_subs();
    return 0;
}