//
// Created by Dmitry Kochetkov on 4/19/2021.
//

#include <bits/stdc++.h>

using namespace std;

struct sliding_window {
    deque<pair<long, long>> d;
    long l = 0, r = 0;

    void push_back(int x){
        while(!d.empty() && d.back().first >= x) d.pop_back();
        d.emplace_back(x,r);
        ++r;
    }

    void pop_front(){
        if(d.front().second == l) d.pop_front();
        ++l;
    }

    int get_min(){
        return d.empty() ? LONG_MAX : d.front().first;
    }
};

int main() {
    long n, k;
    std::cin >> n >> k;

    sliding_window w;

    for (long i = 0; i < k; i++) {
        long x;
        std::cin >> x;
        w.push_back(x);
    }

    std::cout << w.get_min() << std::endl;

    for (long i = k; i < n; i++) {
        w.pop_front();
        long x;
        std::cin >> x;
        w.push_back(x);
        std::cout << w.get_min() << std::endl;
    }
    return 0;
}