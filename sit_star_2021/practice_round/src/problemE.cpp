//
// Created by Dmitry Kochetkov on 2/7/2021.
//

#include <iostream>
#include <algorithm>
#include <vector>

unsigned long long pieces(unsigned long long k) {
    if (k % 2 == 0)
        return (1 + k/2) * (1 + k/2);
    return (1 + k/2) * (2 + k/2);
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        unsigned long long k;
        std::cin >> k;
        std::cout << pieces(k) << std::endl;
    }
    return 0;
}