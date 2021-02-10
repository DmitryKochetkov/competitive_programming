//
// Created by Dmitry Kochetkov on 2/7/2021.
//

#include <bits/stdc++.h>

std::vector<long long> fib(50, 0);

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Finds any solution for equation a * x + b * y = c, writes answer to x and y
void diophantineBasicSolution(long long a, long long b, long long c, long long &x, long long &y) {
    long long g = extgcd(a, b, x, y);

    if (c % g != 0) {
        return;
    }

    c /= g;

    x = x * c; y = y * c;
}

long long problemL_solution(long long x) {
    std::set<std::pair<long long, long long>> solutions;

    for (long i = 0; (i < fib.size()-1) && ((fib[i] + fib[i+1])) <= x; i++) {
//        std::cout << "diophantes equation: " + std::to_string(fib[i]) + " * A + " + std::to_string(fib[i+1]) + " * B = " << x << std::endl;
        long long sol1, sol2;
        long long g = gcd(fib[i], fib[i+1]);

        diophantineBasicSolution(fib[i], fib[i+1], x, sol1, sol2);
        if (sol1 > 0 && sol2 > 0)
            solutions.insert(std::pair<long long, long long>(sol1, sol2));

        while (sol2 < 0) {
            sol1 -= fib[i+1] / g;
            sol2 += fib[i] / g;
        }

        if (sol1 > 0 && sol2 > 0)
            solutions.insert(std::pair<long long, long long>(sol1, sol2));

        while (sol1 < 0) {
            sol1 += fib[i+1] / g;
            sol2 -= fib[i] / g;
        }

        if (sol1 > 0 && sol2 > 0)
            solutions.insert(std::pair<long long, long long>(sol1, sol2));

        if (sol1 < sol2) {
            while (sol2 > 0) {
                sol1 += fib[i+1] / g;
                sol2 -= fib[i] / g;
                if (sol1 > 0 && sol2 > 0)
                    solutions.insert(std::pair<long long, long long>(sol1, sol2));
//                std::cout << "Solution: A = " << sol1 << ", B = " << sol2 << std::endl;
            }
        }
        else {
            while (sol1 > 0) {
                sol1 -= fib[i+1] / g;
                sol2 += fib[i] / g;
                if (sol1 > 0 && sol2 > 0)
                    solutions.insert(std::pair<long long, long long>(sol1, sol2));
//                std::cout << "Solution: A = " << sol1 << ", B = " << sol2 << std::endl;
            }
        }
    }
    return solutions.size();
}

int main() {
    fib[0] = 1;
    fib[1] = 1;
    for (long i = 2; i < fib.size(); i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    long t;
    std::cin >> t;
    while (t--) {
        long long x;
        std::cin >> x;

        std::cout << problemL_solution(x) << std::endl;
    }
    return 0;
}