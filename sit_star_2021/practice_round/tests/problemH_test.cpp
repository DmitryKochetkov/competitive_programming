//
// Created by Dmitry Kochetkov on 2/9/2021.
//

#include <gtest/gtest.h>

std::string predict(std::string s, long long k) {
    long long index = s.find('*');

    for (long long i = 0; i < s.size(); i++) {
        if (i < k)
        if (i+k < s.size() && s[i+k] == '*')
            index = i+k;
        if (std::abs(index - i) <= k)
            s[i] = '*';
    }

    return s;
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(problemH, starsPrefix)
{
    EXPECT_EQ("***..", predict("**...", 1));
    EXPECT_EQ("****.", predict("**...", 2));
}

TEST(problemH, startMiddle) {
    EXPECT_EQ(".***.", predict("..*..", 1));
    EXPECT_EQ("****.", predict("**...", 2));
    EXPECT_EQ("..*****..", predict("...*.*...", 1));
    EXPECT_EQ(".*******.", predict("...*.*...", 2));
}

TEST(problemH, openTest1) {
    EXPECT_EQ("*....**....", predict("*....**....", 2));
}
