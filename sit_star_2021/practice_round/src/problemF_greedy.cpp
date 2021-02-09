//
// Created by Dmitry Kochetkov on 2/7/2021.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

bool containsOnesAndTwos(unsigned long long x) {
    while (x > 0) {
        if (x % 10 != 1 && x % 10 != 2)
            return false;
        x /= 10;
    }
    return true;
}

unsigned long long findNumber(int n) {
    unsigned long long k = 1;
    unsigned long long l = 0;
    unsigned long long r = 0;

    for (int i = 0; i < n; i++) {
        k *= 2;
        l *= 10;
        l += 1;
        r *= 10;
        r += 2;
    }

    std::cout << l << " " << r << " ";

    for (unsigned long long i = l; i <= r; i++) {
        if (i % k == 0 && containsOnesAndTwos(i))
            return i;
    }

    return 0;
}

int main() {
    for (int i = 1; i < 18; i++)
        std::cout << "n = " << i << "; " << findNumber(i) << std::endl;
    return 0;
}