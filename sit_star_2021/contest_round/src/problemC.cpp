//
// Created by Dmitry Kochetkov on 2/10/2021.
//

#include <bits/stdc++.h>

bool isPrime(unsigned long long p) {
    for (unsigned long long i = 2; i <= std::sqrt(p); i++) {
        if (p % i == 0)
            return false;
    }
    return true;
}

bool possibleTiles(unsigned long long n, unsigned long long m, unsigned long long p) {
    if (p <= n || p <= m)
        return true;
    if (p / m > n || isPrime(p))
        return false;

    for (unsigned long long i = 2; i < std::sqrt(p) + 1; i++) {
        if (p % i == 0 && (((i <= n) && (p / i <= m)) || ((i <= m) && (p / i <= n))))
            return true;
    }

    return false;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        unsigned long long n, m, p;
        std::cin >> n >> m >> p;

        std::cout << (possibleTiles(n, m, p) ? "YES" : "NO") << std::endl;
    }
    return 0;
}