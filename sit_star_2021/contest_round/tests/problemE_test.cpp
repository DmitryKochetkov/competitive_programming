//
// Created by Dmitry Kochetkov on 2/10/2021.
//

#include <gtest/gtest.h>

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (b == 0)
        return a;
    std::cout << a << " " << b << " " << (a > b ? a/b : b/a) << std::endl;
    return gcd(b, a % b);
}

//unsigned long long findDay(unsigned long long x, unsigned long long y) {
//    if (x == 0 || y == 0)
//        return -1;
//    if (x == 1 && y == 1)
//        return 0;
//    if (y == 1)
//        return x-1;
//    if (x == 1)
//        return y-1;
//    unsigned long long prev = y > x ?  findDay(x, y - x) : findDay(y, x - y);
//    if (prev == -1)
//        return -1;
//    return prev + 1;
//}

long long findDay(long long x, long long y) {
    if (x == 0 || y == 0)
        return -1;
    if (x == 1 && y == 1)
        return 0;
    if (y == 1)
        return x-1;
    if (x == 1)
        return y-1;
    long long prev = y > x ? findDay(x, y % x) : findDay(y, x % y);
    if (prev == -1)
        return -1;
    return prev + std::max(y / x, x / y);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(problemE, openTest1) {
    EXPECT_EQ(0, findDay(1, 1));
    EXPECT_EQ(1, findDay(1, 2));
    EXPECT_EQ(2, findDay(3, 1));
    EXPECT_EQ(999999999999999999, findDay(1000000000000000000, 1));
}

TEST(problemE, openTest2) {
    EXPECT_EQ(-1, findDay(42, 1337));
}

TEST(problemE, openTest3) {
    EXPECT_EQ(832, findDay(998244353, 1000000007));
};