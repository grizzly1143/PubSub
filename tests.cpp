#include <gtest/gtest.h>
#include "subscriber.h"
#include "publisher.h"

TEST(TestPubSub, Subscription) {
    bool status = false;
    Publisher pub("Pub1");
    std::shared_ptr<Subscriber> sub1 = std::make_shared<Subscriber>("Sub1");
    std::shared_ptr<Subscriber> sub2 = std::make_shared<Subscriber>("Sub2");
    status = pub.subsribe(sub1);
    ASSERT_TRUE(status);
    status = pub.subsribe(sub2);
    ASSERT_TRUE(status);
    std::string mes = "Test message";
    status = pub.publish(mes);
    ASSERT_TRUE(status);
    std::string sub1_mes = sub1->get_last_message();
    std::string sub2_mes = sub2->get_last_message();
    ASSERT_EQ(mes, sub1_mes);
    ASSERT_EQ(mes, sub2_mes);
}

TEST(TestPubSub, Unsubscribe) {
    bool status = false;
    Publisher pub("Pub1");
    std::shared_ptr<Subscriber> sub1 = std::make_shared<Subscriber>("Sub1");
    std::shared_ptr<Subscriber> sub2 = std::make_shared<Subscriber>("Sub2");
    status = pub.subsribe(sub1);
    ASSERT_TRUE(status);
    status = pub.subsribe(sub2);
    ASSERT_TRUE(status);
    std::string mes = "Test message";
    status = pub.publish(mes);
    ASSERT_TRUE(status);
    status = pub.unsubscribe(sub1);
    ASSERT_TRUE(status);
    std::string mes2 = "Test message2";
    status = pub.publish(mes2);
    ASSERT_TRUE(status);
    std::string sub1_mes = sub1->get_last_message();
    std::string sub2_mes = sub2->get_last_message();
    ASSERT_EQ(mes, sub1_mes);
    ASSERT_EQ(mes2, sub2_mes);
}

TEST(TestPubSub, Empty_list) {
    bool status = false;
    Publisher pub("Pub1");
    std::shared_ptr<Subscriber> sub1 = std::make_shared<Subscriber>("Sub1");
    std::shared_ptr<Subscriber> sub2 = std::make_shared<Subscriber>("Sub2");
    status = pub.subsribe(sub1);
    ASSERT_TRUE(status);
    status = pub.subsribe(sub2);
    ASSERT_TRUE(status);
    std::string mes = "Test message";
    status = pub.publish(mes);
    ASSERT_TRUE(status);
    status = pub.unsubscribe(sub1);
    ASSERT_TRUE(status);
    status = pub.unsubscribe(sub2);
    ASSERT_TRUE(status);
    std::string mes2 = "Test message2";
    status = pub.publish(mes2);
    ASSERT_FALSE(status);
    std::string sub1_mes = sub1->get_last_message();
    std::string sub2_mes = sub2->get_last_message();
    ASSERT_EQ(mes, sub1_mes);
    ASSERT_EQ(mes, sub2_mes);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}