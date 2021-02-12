//
// Created by Dmitry Kochetkov on 2/8/2021.
//

#include <iostream>
#include <algorithm>

std::string predict(std::string s, long long k) {
    long long index = s.find('*');
    long long index2 = -1;

    for (long long i = 0; i < s.size(); i++) {
        if (i < k && s[i] == '*')
            index2 = i;
        if (i+k < s.size() && s[i+k] == '*')
            index = i+k;
        if (std::abs(index - i) <= k)
            s[i] = '*';
        if (index2 > 0 && std::abs(index2 - i) <= k)
            s[i] = '*';
    }

    return s;
}

int main() {
    long long n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::cout << predict(s, k) << std::endl;
    return 0;
}