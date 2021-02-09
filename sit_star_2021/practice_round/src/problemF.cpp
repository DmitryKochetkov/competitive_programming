//
// Created by Dmitry Kochetkov on 2/7/2021.
//

#include <iostream>
#include <algorithm>
#include <vector>

unsigned long long findNumber(int n) {
    if (n == 1)
        return 2;

    unsigned long long prev = findNumber(n-1);

    unsigned long long k = 1;
    unsigned long long t = 1;

    for (int i = 0; i < n; i++) {
        k *= 2;
        t *= 10;
    }
    t /= 10;

    if ((t + prev) % k == 0)
        return t + prev;
    else return 2ULL * t + prev;

//    return -1;
}

int main() {
    int n;
    std::cin >> n;

    std::cout << findNumber(n) << std::endl;
    return 0;
}