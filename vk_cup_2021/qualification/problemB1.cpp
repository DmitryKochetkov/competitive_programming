//
// Created by Dmitry Kochetkov on 5/29/2021.
//

#include <iostream>
#include <vector>
#include <algorithm>

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

    long res = 0;

    for (long i = 0; i < n; i++)
        for (long j = 0; j < i; j++)
            if (a[i].first == a[j].first || a[i].second == a[j].second || a[i].first == a[j].second || a[i].second == a[j].first)
                res++;

    std::cout << res << std::endl;
    return 0;
}