//
// Created by Dmitry Kochetkov on 2/10/2021.
//

#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int x, y;
        std::cin >> x >> y;

        int t1 = 20 * (x-1);
        int t2 = (y-1) * 5 + (x-1) * 5;

        int ans = std::min(t1, t2);

        std::cout << ans << std::endl;
    }
    return 0;
}