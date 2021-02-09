//
// Created by Dmitry Kochetkov on 2/7/2021.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        unsigned long long n;
        std::cin >> n;

        unsigned long long res = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 5 == 0)
                res += 5;
            else if (i % 3 == 0)
                res += 3;
            else if (i % 2 == 0)
                res += 2;
            else res += 1;
        }
        std::cout << res << std::endl;
    }
    return 0;
}