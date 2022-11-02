//
// Created by Dmitry Kochetkov on 3/6/2021.
//

#include <bits/stdc++.h>
#include <numeric>

long gcd(long a, long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<long> a(n);

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    long m = a[0];
    for (int i = 1; i < n; i++)
        m = gcd(m, a[i]);

    while (q--) {
        long i, x;
        std::cin >> i >> x;

        a[i-1] *= x;
        m = gcd(m, a[i-1]);
        std::cout << m << std::endl;
    }
    return 0;
}
