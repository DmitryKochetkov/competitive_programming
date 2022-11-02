//
// Created by Dmitry Kochetkov on 5/29/2021.
//

#include <iostream>
#include <vector>
#include <algorithm>

int binomialCoefficients(long n, long k) {
    std::vector<int> C(k+1, 0);
    C[0] = 1;
    for (long i = 1; i <= n; i++) {
        for (long j = std::min(i, k); j > 0; j--)
            C[j] = C[j] + C[j-1];
    }
    return C[k];
}

int main() {
    long n;
    std::cin >> n;

    std::vector<std::pair<long, long>> a;
    for (long i = 0; i < n; i++) {
        long w, h;
        std::cin >> w >> h;

        if (w > h)
            std::swap(w, h);

        a.push_back(std::pair<long, long>(w, h));
    }



//    std::sort(a.begin(), a.end(), [](const std::pair<long, long>& a, const std::pair<long, long> b) {
//        return
//    });

    std::sort(a.begin(), a.end());
    for (auto p: a) {
        std::cout << p.first << " " << p.second << std::endl;
    }

    long res = 0;
    long c = 1;
    long x = a[0].first;
    for (long i = 0; i < a.size(); i++) {
        if (a[i].first == x) {
            c++;
            res += c / 2;
        }
        else {
            res += c / 2;
            c = 1;
            x = a[i].first;
        }
    }
    res += c / 2;

    std::cout << res << std::endl;
    return 0;
}