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

        std::vector<int> a(n);

        for (int i = 0; i < n; i+=2) {
            a[i] = i+2;
            a[i+1] = i+1;
        }

        if (n % 2 == 1) {
            a[n-1]--;
            std::swap(a[n - 1], a[n - 2]);
        }

        for (int i = 0; i < n; i++)
            std::cout << a[i] << " ";

        std::cout << std::endl;
    }
    return 0;
}