//
// Created by Dmitry Kochetkov on 4/10/2021.
//

#include <iostream>
#include <climits>

int main() {
    unsigned long long n;
    std::cin >> n;
    if (n % 3 == 0)
        std::cout << n / 3 << std::endl;
    else if (n % 3 == 1) {
        std::cout << ULLONG_MAX / 3 * 2 + n/3 + 1 << std::endl;
    }
    else if (n % 3 == 2)
        std::cout << ULLONG_MAX / 3 + n/3 + 1 << std::endl;
    return 0;
}