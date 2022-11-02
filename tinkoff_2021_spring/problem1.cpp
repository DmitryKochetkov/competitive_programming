//
// Created by Dmitry Kochetkov on 4/11/2021.
//

#include <bits/stdc++.h>

int main() {
    int x1, x2;
    int y1, y2;

    std::cin >> x1 >> x2 >> y1 >> y2;
    if (x1 > x2)
        std::swap(x1, x2);

    if (y1 > y2)
        std::swap(y1, y2);

    if (x1 == y1) {
        std::cout << x2 << " " << x1 << " " << y1 << " " << y2 << std::endl;
    }
    else if (x2 == y2) {
        std::cout << x1 << " " << x2 << " " << y2 << " " << x2 << std::endl;
    }
    else std::cout << "-1" << std::endl;
    return 0;
}