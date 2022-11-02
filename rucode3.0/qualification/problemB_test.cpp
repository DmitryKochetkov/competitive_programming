//
// Created by Dmitry Kochetkov on 2/10/2021.
//

#include <gtest/gtest.h>
#include <bits/stdc++.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(problemA, test1) {
    EXPECT_EQ(2, 2);
}