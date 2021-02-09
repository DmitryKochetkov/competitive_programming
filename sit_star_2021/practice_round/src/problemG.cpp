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
        unsigned long long count5 = n / 5;
        unsigned long long count3 = n / 3 - n / 15;
        unsigned long long count2 = n / 2 - n / (2 * 3) - n / (2 * 5) + n / 30;
        unsigned long long count1 = n - count5 - count3 - count2;
        res = count5 * 5 + count3 * 3 + count2 * 2 + count1;

        std::cout << res << std::endl;
    }
    return 0;
}