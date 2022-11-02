//
// Created by Dmitry Kochetkov on 4/11/2021.
//

#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m);
    std::vector<bool> flag(m, true);

    for (int i = 0; i < m; i++) {
        int x;
        std::cin >> x;
        a[i] = x;
    }

    int c = 0;
    int t = 1;
    while (c < n) {
        for (int i = 0; i < a.size(); i++)
            if ((t % a[i] == 0)) {
                if (flag[i])
                    c++;
                flag[i] = !flag[i];
            }
        t++;
    }

    std::cout << t-1 << std::endl;
    return 0;
}