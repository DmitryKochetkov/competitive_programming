//
// Created by Dmitry Kochetkov on 4/11/2021.
//

#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), dp(n);

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    dp[n-1] = 1;
    int max_height = a[n-1];

    for (int i = n-2; i >= 0; i--) {
        if (a[i] > max_height) {
            dp[i] = 1;
            max_height = a[i];
        }
        else dp[i] = dp[i+1] + (a[i] > a[i+1] ? 0 : 1);
    }

    for (auto x: dp)
        std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}