//
// Created by Dmitry Kochetkov on 5/29/2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

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

    std::map<long, long> all;

    long res = 0;
    long x = a[0].first;
    all[a[0].second] = 1;
    long k = 1;
    for (long i = 1; i < a.size(); i++) {
        if (a[i].first > x) {
            long f = k + all[x];
            res += f * (f-1) / 2;
            x = a[i].first;
        }
        else if (a[i].first == x) {
            k++;
            if (all.find(a[i].second) == all.end())
                all[a[i].second] = 1;
            else all[a[i].second]++;
        }
    }
    long f = k;
    res += f * (f-1) / 2;

//    for (auto i: all)
//        res += i.second * (i.second - 1) / 2;

    std::cout << res << std::endl;
    return 0;
}