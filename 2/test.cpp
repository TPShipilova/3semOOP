#include <iostream>
#include "binary.h"
#include "gtest/gtest.h"
#include <stdexcept>

TEST(BinaryOperatorPlus, SameBitValues){
    Binary b1("10101");
    Binary b2("10101");
    Binary result = b1 + b2;
    ASSERT_EQ(result.getBits(), "101010");
}

TEST(BinaryOperatorPlus, DifferentBitValues){
    Binary b1("10101");
    Binary b2("11011");
    Binary result = b1 + b2;
    ASSERT_EQ(result.getBits(), "110000");
}

TEST(BinaryOperatorMinus, SameBitValues){
    Binary b1("10101");
    Binary b2("10101");
    Binary result = b1 - b2;
    ASSERT_EQ(result.getBits(), "00000");
}

TEST(test_02, subtract_from_smaller_number){  
    Binary b1("1010"); 
    Binary b2("1111"); 
    ASSERT_THROW(b2-b1, std::invalid_argument); 
}

TEST(BinaryOperatorEquals, AssignToAnotherBinary){
    Binary b1("10101");
    Binary b2("11011");
    b1 = b2;
    ASSERT_EQ(b1.getBits(), "11011");
}

TEST(BinaryOperatorEquals, AssignToItself){
    Binary b1("10101");
    b1 = b1;
    ASSERT_EQ(b1.getBits(), "10101");
}

TEST(BinaryOperatorEquals, AssignEmptyBinary){
    Binary b1("10101");
    Binary b2;
    b1 = b2;
    ASSERT_EQ(b1.getBits(), "");
}

TEST(BinaryOperatorEquals, AssignToEmptyBinary){
    Binary b1;
    Binary b2("11011");
    b1 = b2;
    ASSERT_EQ(b1.getBits(), "11011");
}

TEST(BinaryOperatorEquals, AssignEmptyBinaryToEmptyBinary){
    Binary b1;
    Binary b2;
    b1 = b2;
    ASSERT_EQ(b1.getBits(), "");
}

TEST(BinaryOperatorEqual, SameBitValues){
    Binary b1("10101");
    Binary b2("10101");
    ASSERT_TRUE(b1 == b2);
}

TEST(BinaryOperatorEqual, DifferentBitValues){
    Binary b1("10101");
    Binary b2("11011");
    ASSERT_FALSE(b1 == b2);
}

TEST(BinaryOperatorNotEqual, SameBitValues){
    Binary b1("10101");
    Binary b2("10101");
    ASSERT_FALSE(b1 != b2);
}

TEST(BinaryOperatorNotEqual, DifferentBitValues){
    Binary b1("10101");
    Binary b2("11011");
    ASSERT_TRUE(b1 != b2);
}

TEST(BinaryOperatorLessThan, SameBitValues){
    Binary b1("10101");
    Binary b2("10101");
    ASSERT_FALSE(b1 < b2);
}

TEST(BinaryOperatorLessThan, FirstBinarySmaller){
    Binary b1("10101");
    Binary b2("11011");
    ASSERT_TRUE(b1 < b2);
}

TEST(BinaryOperatorLessThan, FirstBinaryLarger){
    Binary b1("11011");
    Binary b2("10101");
    ASSERT_FALSE(b1 < b2);
}

TEST(BinaryOperatorGreaterThan, SameBitValues){
    Binary b1("10101");
    Binary b2("10101");
    ASSERT_FALSE(b1 > b2);
}

TEST(BinaryOperatorGreaterThan, FirstBinarySmaller){
    Binary b1("10101");
    Binary b2("11011");
    ASSERT_FALSE(b1 > b2);
}

TEST(BinaryOperatorGreaterThan, FirstBinaryLarger){
    Binary b1("11011");
    Binary b2("10101");
    ASSERT_TRUE(b1 > b2);
}