//
// Created by Dmitry Kochetkov on 2/7/2021.
//

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    int count5 = 0;
    int count3 = 0;
    int count2 = 0;
    int count1 = 0;

    for (int i = 1; i <= n; i++)
        if (i % 5 == 0)
            count5 += 1;
        else if (i % 3 == 0)
            count3 += 1;
        else if (i % 2 == 0)
            count2 += 1;
        else count1 += 1;

    std::cout << "Count5: expected " << count5 << ", actual " << n / 5 << std::endl;
    std::cout << "Count3: expected " << count3 << ", actual " << n / 3 - n / 15 << std::endl;
    std::cout << "Count2: expected " << count2 << ", actual " << n / 2 - n / (2 * 3) - n / (2 * 5) + n / 30 << std::endl;
    std::cout << "Count1: expected " << count1 << ", actual " << n - n / 5 - (n / 3 - n / 15) - (n / 2 - n / (2 * 3) - n / (2 * 5)) << std::endl;
    return 0;
}