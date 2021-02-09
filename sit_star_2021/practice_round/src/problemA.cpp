//
// Created by Dmitry Kochetkov on 2/6/2021.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    std::vector<int> a(3);
    while (t--) {
        std::cin >> a[0] >> a[1] >> a[2];
        std::sort(a.begin(), a.end());
        if (a[0] * a[1] == a[2]) {
            std::cout << "YES" << std::endl;
            std::cout << a[0] << " " << a[1] << " " << a[2] << std::endl;
        }
        else if (a[0] == 0 && a[1] == 0) {
            std::cout << "YES" << std::endl;
            std::cout << a[2] << " " << a[1] << " " << a[0] << std::endl;
        }
        else std::cout << "NO" << std::endl;
    }
    return 0;
}