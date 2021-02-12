//
// Created by Dmitry Kochetkov on 2/10/2021.
//

#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long x1, y1, x2, y2, x3, y3;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        long x4, y4;
        if (x1 == x2)
            x4 = x3;
        else if (x1 == x3)
            x4 = x2;
        else x4 = x1;

        if (y1 == y2)
            y4 = y3;
        else if (y1 == y3)
            y4 = y2;
        else y4 = y1;

        std::cout << x4 << " " << y4 << std::endl;
    }
    return 0;
}