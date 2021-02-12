//
// Created by Dmitry Kochetkov on 2/10/2021.
//

#include <gtest/gtest.h>
#include <bits/stdc++.h>

bool isPrime(unsigned long long p) {
    for (long i = 2; i <= std::sqrt(p); i++) {
        if (p % i == 0)
            return false;
    }
    return true;
}

bool possibleTilesGreedy(unsigned long long n, unsigned long long m, unsigned long long p) {
    if (n * m < p)
        return false;

    for (unsigned long long i = 1; i <= n; i++)
        for (unsigned long long j = 1; j <= m; j++)
            if (i * j == p)
                return true;
    return false;
}

bool possibleTiles(unsigned long long n, unsigned long long m, unsigned long long p) {
    if (p <= n || p <= m)
        return true;
    if (p / m > n || isPrime(p))
        return false;

    for (unsigned long long i = 2; i < std::sqrt(p) + 1; i++) {
        if (p % i == 0 && (((i <= n) && (p / i <= m)) || ((i <= m) && (p / i <= n))))
            return true;
    }

    return false;

}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(problemC, test1) {
    EXPECT_EQ(true, possibleTiles(6, 2, 4));
}

TEST(problemC, test2) {
    EXPECT_EQ(true, possibleTiles(7, 3, 8));
}

TEST(problemC, test3) {
    EXPECT_EQ(false, possibleTiles(3, 4, 5));
}

TEST(problemC, test4) {
    EXPECT_EQ(false, possibleTiles(4, 4, 15));
}

TEST(problemC, test5) {
    EXPECT_EQ(true, possibleTiles(1, 1, 1));
    EXPECT_EQ(false, possibleTiles(1, 1, 2));
    EXPECT_EQ(false, possibleTiles(1, 1, 4));
    EXPECT_EQ(true, possibleTiles(2, 2, 2));
}

TEST(problemC, test6) {
    EXPECT_EQ(true, possibleTiles(2, 2, 4));
    EXPECT_EQ(false, possibleTiles(2, 2, 5));
    EXPECT_EQ(false, possibleTiles(2, 2, 3));
}

TEST(problemC, test7) {
    EXPECT_EQ(true, possibleTiles(2, 1, 1));
}

TEST(problemC, test8) {
    EXPECT_EQ(true, possibleTiles(3, 3, 4));
    EXPECT_EQ(false, possibleTiles(3, 3, 5));
    EXPECT_EQ(true, possibleTiles(3, 3, 6));
    EXPECT_EQ(false, possibleTiles(3, 3, 7));
    EXPECT_EQ(false, possibleTiles(3, 3, 8));
    EXPECT_EQ(true, possibleTiles(3, 3, 9));
}

TEST(problemC, test8_greedy) {
    EXPECT_EQ(true, possibleTilesGreedy(3, 3, 4));
    EXPECT_EQ(false, possibleTilesGreedy(3, 3, 5));
    EXPECT_EQ(true, possibleTilesGreedy(3, 3, 6));
    EXPECT_EQ(false, possibleTilesGreedy(3, 3, 7));
    EXPECT_EQ(false, possibleTilesGreedy(3, 3, 8));
    EXPECT_EQ(true, possibleTilesGreedy(3, 3, 9));
}

TEST(problemC, greedy_test) {
    for (unsigned long long n = 1; n < 10; n++)
        for (unsigned long long m = 1; m < 10; m++)
            for (unsigned long long p = 1; p < 100; p++) {
                std::cout << "n = " << n << ", m = " << m << ", p = " << p << std::endl;
                EXPECT_EQ(possibleTilesGreedy(n, m, p), possibleTiles(n, m, p));
            }
}