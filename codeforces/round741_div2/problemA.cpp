//
// Created by Dmitry Kochetkov on 8/27/2021.
//

#include <bits/stdc++.h>

int main() {
    int t;
    while (t--) {
        long l, r;
        std::cin >> l >> r;

        if (l % r == 0)
            std::cout << r % (l + 1) << std::endl;
        else std::cout << ((r - l + 1) / 2) % r << std::endl;
    }
    return 0;
}