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

    std::sort(a.begin(), a.end());

    long res = 0;
    long c = 1;
    long c2 = 1;
    long x = a[0].first;
    long y = a[0].second;

    if (y == x)
        y = -1;

    for (long i = 1; i < a.size(); i++) {
        if (a[i].first == x) {
            c++;
        }
        else {
            res += c * (c-1) / 2;
            c = 1;
            if (a[i].first == a[i-1].second) {
                c += c2;
                c2 = -1;
            }
            x = a[i].first;
        }

        if (a[i].second == y)
            c2 += 1;
        if (a[i].second > y) {
            y = a[i].second;
            c2 = 1;
        }
    }
    if (a[a.size()].first == a[a.size()-1].second)
        c += c2;
    res += c * (c-1) / 2;

    std::cout << res << std::endl;
    return 0;
}