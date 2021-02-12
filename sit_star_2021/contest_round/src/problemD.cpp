//
// Created by Dmitry Kochetkov on 2/10/2021.
//

#include <bits/stdc++.h>

void possibleParking(long n, long a, long b, std::string s) {
    std::vector<std::pair<long, long>> big;
    std::vector<long> small;
    for (long i = 0; i < s.size()-1 && a > 0; i++) {
        if (s[i] == '0' && s[i+1] == '0') {
            s[i] = '1';
            s[i+1] = '1';
            big.push_back(std::pair<long, long>(i, i+1));
            a--;
        }
    }

    if (a > 0) {
        std::cout << "NO" << std::endl;
        return;
    }

    for (long i = 0; i < s.size() && b > 0; i++) {
        if (s[i] == '0') {
            b--;
            small.push_back(i);
        }
    }

    if (b > 0) {
        std::cout << "NO" << std::endl;
        return;
    }

    std::cout << "YES" << std::endl;
    for (auto p: big) {
        std::cout << p.first + 1 << " " << p.second + 1 << std::endl;
    }

    for (auto x: small) {
        std::cout << x + 1 << std::endl;
    }
}

int main() {
    long n, a, b;
    std::string s;
    std::cin >> n >> a >> b;
    std::cin >> s;

    possibleParking(n, a, b, s);
    return 0;
}