//
// Created by Dmitry Kochetkov on 4/10/2021.
//

#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> m >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    std::vector<std::vector<int>> dp(n, std::vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + std::abs(a[i][0] - a[i-1][0]);
    }

    for (int i = 1; i < m; i++) {
        dp[0][i] = dp[0][i-1] + std::abs(a[0][i] - a[0][i-1]);
    }

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            dp[i][j] = std::min(
                    dp[i-1][j] + std::abs(a[i][j] - a[i-1][j]),
                    dp[i][j-1] + std::abs(a[i][j] - a[i][j-1])
                    );

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++)
//            std::cout << dp[i][j] << " ";
//        std::cout << std::endl;
//    }

    std::cout << dp[n-1][m-1] << std::endl;
    return 0;
}