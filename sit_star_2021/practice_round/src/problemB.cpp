//
// Created by Dmitry Kochetkov on 2/6/2021.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        if  (n % 3 == 0)
            std::cout << n/3 - 1 << " " << n/3 << " " << n/3 + 1 << std::endl;
        else std::cout << -1 << std::endl;
    }
    return 0;
}