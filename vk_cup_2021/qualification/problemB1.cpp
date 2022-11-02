//
// Created by Dmitry Kochetkov on 5/29/2021.
//

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    bool locked = false;
    std::string color = "blue";

    for (int i = 0; i < n; i++) {
        std::string input;
        std::cin >> input;

        if (input == "lock")
            locked = true;
        else if (input == "unlock")
            locked = false;
        else if (!locked)
            color = input;
    }

    std::cout << color << std::endl;
    return 0;
}