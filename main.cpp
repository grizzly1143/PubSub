#include "publisher.h"
#include "subscriber.h"

int main() {
    Publisher pub("Pub1");
    Subscriber sub1("Sub1");
    pub.subsribe(&sub1);
    Subscriber sub2("Sub2");
    pub.subsribe(&sub2);
    pub.print_subs();
    pub.publish("Test publication");
    pub.unsubscribe(&sub2);
    pub.print_subs();
    return 0;
}