//#include "googletest/googletest/include/gtest/gtest.h"
#include "gtest/gtest.h"
#include "computator.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(count_cuts(1,2)==1);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(count_cuts(10,2)==19);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(count_cuts(4,4)==15);
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(count_cuts(1,1)==0);
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(count_cuts(-1,1)==-1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}