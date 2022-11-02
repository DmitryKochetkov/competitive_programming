//
// Created by Dmitry Kochetkov on 6/25/2021.
//

#include <bits/stdc++.h>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;

        std::cout << n << " ";
        for (int i = 1; i <= n-1; i++)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    return 0;
}