//
// Created by Dmitry Kochetkov on 4/11/2021.
//

#include <bits/stdc++.h>

int main() {
    int a, b, c, t;
    std::cin >> a >> b >> c >> t;

    int s = t % c;
    int m = (t / c) % b;
    int h = t / c / b;

    std::cout << h << " " << m << " " << s << " " << std::endl;
    return 0;
}