//
// Created by Dmitry Kochetkov on 2/10/2021.
//

#include <bits/stdc++.h>

long long findDay(long long x, long long y) {
    if (x == 0 || y == 0)
        return -1;
    if (x == 1 && y == 1)
        return 0;
    if (y == 1)
        return x-1;
    if (x == 1)
        return y-1;
    long long prev = y > x ? findDay(x, y % x) : findDay(y, x % y);
    if (prev == -1)
        return -1;
    return prev + std::max(y / x, x / y);
}

int main() {
    long t;
    std::cin >> t;
    while (t--) {
        long long x, y;
        std::cin >> x >> y;
        std::cout << findDay(x, y) << std::endl;
    }
    return 0;
}