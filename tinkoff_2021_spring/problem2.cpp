//
// Created by Dmitry Kochetkov on 4/11/2021.
//

#include <bits/stdc++.h>

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

bool isBeautiful(std::string s) {
    for (int i = 0; i < s.size() - 1; i++)
        if (isVowel(s[i]) == isVowel(s[i+1]))
            return false;
    return true;
}

int main() {
    std::string s;
    std::cin >> s;

    std::cout << (isBeautiful(s) ? "YES" : "NO") << std::endl;
    return 0;
}