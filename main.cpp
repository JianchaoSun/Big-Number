

#include <gtest/gtest.h>
#include "BigNumber.h"

class TestBigNumbers : public testing::Test {

};

TEST_F(TestBigNumbers, add) {
    BigNumber first("100");
    BigNumber second("300");

    BigNumber actual = first + second;


    ASSERT_TRUE(actual.v[0] == 0&&actual.v[1] == 0&&actual.v[2] == 4);
}

TEST_F(TestBigNumbers, mul) {
    BigNumber first("10");
    BigNumber second("30");

    BigNumber actual = first * second;


    ASSERT_TRUE(actual.v[0] == 0&&actual.v[1] == 0&&actual.v[2] == 3);
}

TEST_F(TestBigNumbers, div) {
    BigNumber first("300");
    BigNumber second("100");

    BigNumber actual = first /second;


    ASSERT_TRUE(actual.v[0] == 3);
}

TEST_F(TestBigNumbers, mod) {
    BigNumber first("29");
    BigNumber second("3");

    BigNumber actual = first %second;


    ASSERT_TRUE(actual.v[0] == 2);
}

TEST_F(TestBigNumbers, sub) {
    BigNumber first("29");
    BigNumber second("3");

    BigNumber actual = first -second;


    ASSERT_TRUE(actual.v[0] == 6&&actual.v[1] == 2);
}
