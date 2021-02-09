//
// Created by Dmitry Kochetkov on 2/7/2021.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        std::vector<int> a(3);
        std::vector<int> b(3);

        std::cin >> a[0] >> a[1] >> a[2];
        std::cin >> b[0] >> b[1] >> b[2];

        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());

        int c = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
        std::cout << c << std::endl;
    }
    return 0;
}