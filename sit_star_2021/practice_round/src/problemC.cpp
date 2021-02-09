//
// Created by Dmitry Kochetkov on 2/6/2021.
//

#include <iostream>
#include <algorithm>
#include <vector>

int bakingTime(long t0, long t1, long t2) {
    if (t2 < t1)
        std::swap(t1, t2);

    if (t0 > t1 && t0 >= t2)
        return t0 - t1;

    if (t0 <= t2 && t0 < t1)
        return t2 - t0;

    long d1 = std::abs(t1 - t0);
    long d2 = std::abs(t2 - t0);

    if (d2 < d1)
        std::swap(d2, d1);
    return 2 * d1 + d2;
}

int main() {
    long t0, t1, t2;
    std::cin >> t0 >> t1 >> t2;

    std::cout << bakingTime(t0, t1, t2) << std::endl;
    return 0;
}