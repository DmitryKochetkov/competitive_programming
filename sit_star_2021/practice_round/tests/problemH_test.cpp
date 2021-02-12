//
// Created by Dmitry Kochetkov on 2/9/2021.
//

#include <gtest/gtest.h>

std::string predict(std::string s, long long k) {
    long long index = s.find('*');
    long long index2 = -1;

    for (long long i = 0; i < s.size(); i++) {
        if (i < k && s[i] == '*')
            index2 = i;
        if (i+k < s.size() && s[i+k] == '*')
            index = i+k;
        if (std::abs(index - i) <= k)
            s[i] = '*';
        if (index2 > 0 && std::abs(index2 - i) <= k)
            s[i] = '*';
    }

    return s;
}

//std::string predict(std::string s, long long k) {
//    long long times = 0;
//
//    for (long long i = 0; i < s.size(); i++) {
//        if (i < k && s[i] == '*')
//            times = k + 1;
//        if (i+k < s.size() && s[i+k] == '*')
//            times = k * 2 + 1;
//        if (times > 0) {
//            s[i] = '*';
//            times--;
//        }
//    }
//
//    return s;
//}


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
    EXPECT_EQ("..*****..", predict("...*.*...", 1));
    EXPECT_EQ(".*******.", predict("...*.*...", 2));
}

TEST(problemH, openTest1) {
    EXPECT_EQ("*********..", predict("*....**....", 2));
}

TEST(problemH, test1) {
    EXPECT_EQ(".......****", predict(".........*.", 2));
}

TEST(problemH, test2) {
    EXPECT_EQ(".****...**", predict("..**.....*", 1));
}

TEST(problemH, test3) {
    EXPECT_EQ("**.", predict("*..", 1));
}
