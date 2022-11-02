//
// Created by Dmitry Kochetkov on 5/29/2021.
//

#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int n = 27;
//    std::cin >> n;
    if (n == 1) {
        std::cout << 1 << std::endl;
        std::cout << "o" << std::endl;
        return 0;
    }

    if (n == 2) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::vector<int> result(n / 2 + n % 2, 1);
    result[0] = n / 2 + n % 2;

    for (int i = 1; i < result.size() / 2;) {
        result[0] -= 2;
        result[i] += 2;
        result[i+1] += 2;
        result.pop_back();
        result.pop_back();

        result[0] -= 2;
        result[i] += 2;
        result[i+2] += 1;
        result[i+3] += 1;
        result.pop_back();
        result.pop_back();

        i+=5;
    }

//    result[1]++;
//    result[0]--;
//    result[result.size()-2]++;
//    result.pop_back();

    for (auto i: result)
        std::cout << i << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::vector<std::vector<char>> output(result[0], std::vector<char>(result.size(), '.'));
    for (int i = 0; i < result.size(); i++)
        for (int j = 0; j < result[i]; j++)
            output[result.size() - 1 - j][i] = 'o';

    for (auto v: output) {
        for (auto c: v)
            std::cout << c;
        std::cout << std::endl;
    }
}