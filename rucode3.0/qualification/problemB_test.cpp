//
// Created by Dmitry Kochetkov on 2/10/2021.
//

#include <gtest/gtest.h>
#include <bits/stdc++.h>

bool isAttacked(int x1, int x2, int y1, int y2, int z1, int z2) {
    bool result = std::abs(x1 - z1) <= 1 && std::abs(x2 - z2) <= 1;
    // checking white king is not between black king and rook
    if (y1 == z1) {
        int a = std::min(y2, z2);
        int b = std::max(y2, z2);
        result = result || (x1 == y1 && (x1 != y1 || (x2 > b || x2 < a)));
    }
    else if (y2 == z2) {
        int a = std::min(y1, z1);
        int b = std::max(y1, z1);
        result = result || (x2 == y2 && (x2 != y2 || (x1 > b || x1 < a)));
    }

    return result;
}

std::string position(std::string s) {
    // white king
    int x1 = s[0] - 'a' + 1;
    int x2 = s[1] - '0';

    // white rook
    int y1 = s[3] - 'a' + 1;
    int y2 = s[4] - '0';

    // black king
    int z1 = s[6] - 'a' + 1;
    int z2 = s[7] - '0';

    if (std::abs(x1 - z1) <= 1 && std::abs(x2 - z2) <= 1)
        return "Strange";

    bool check = isAttacked(x1, x2, y1, y2, z1, z2);

    // let's check all possible moves for black king
    bool can_move_left_down = (z1 - 1 > 0) && (z2 - 1 > 0) && !isAttacked(x1, x2, y1, y2, z1-1, z2-1);
    bool can_move_down = (z2 - 1 > 0) && !isAttacked(x1, x2, y1, y2, z1, z2-1);
    bool can_move_left = (z1 - 1 > 0) && !isAttacked(x1, x2, y1, y2, z1-1, z2);
    bool can_move_right = (z1 + 1 <= 8) && !isAttacked(x1, x2, y1, y2, z1+1, z2);
    bool can_move_right_down = (z1 + 1 <= 8) && (z2 - 1 > 0) && !isAttacked(x1, x2, y1, y2, z1+1, z2-1);
    bool can_move_up = (z2 + 1 <= 8) && !isAttacked(x1, x2, y1, y2, z1, z2 + 1);
    bool can_move_right_up = (z1 + 1 <= 8) && (z2 + 1 <= 8) && !isAttacked(x1, x2, y1, y2, z1+1, z2+1);
    bool can_move_left_up = (z1 - 1 > 0) && (z2 + 1 <= 8) &&  !isAttacked(x1, x2, y1, y2, z1-1, z2+1);

    bool can_move =
            can_move_left ||
            can_move_left_up ||
            can_move_up ||
            can_move_right ||
            can_move_right_up ||
            can_move_down ||
            can_move_right_down ||
            can_move_left_down;

    if (check) {
        if (can_move)
            return "Check";
        else return "Checkmate";
    }
    else {
        if (can_move)
            return "Normal";
        else return "Stalemate";
    }
}

int main(int argc, char *argv[])
{
    std::string s;
    std::cin >> s;
    std::cout << position(s) << std::endl;
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
}

TEST(problemB, testNormal) {
    EXPECT_EQ(position("b2 a3 c4"), "Normal");
}

TEST(problemB, testCheck) {
    EXPECT_EQ(position("a1 b2 e2"), "Check");
}

TEST(problemB, testStalemate) {
    EXPECT_EQ(position("a6 b1 a8"), "Stalemate");
}

TEST(problemB, testCheckmate) {
    EXPECT_EQ(position("b6 h8 a8"), "Checkmate");
}