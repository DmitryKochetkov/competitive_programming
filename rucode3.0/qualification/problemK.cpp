//
// Created by Dmitry Kochetkov on 4/10/2021.
//

#include <bits/stdc++.h>

double distance(std::pair<long, long> x1, std::pair<long, long> x2) {
    long a = std::abs(x1.first - x2.first);
    long b = std::abs(x1.second - x2.second);
    return std::sqrt(a*a + b*b);
}

double area(std::pair<long, long> x1, std::pair<long, long> x2, std::pair<long, long> x3) {
    double a = distance(x1, x2);
    double b = distance(x2, x3);
    double c = distance(x1, x3);

    double p = (a+b+c) / 2;
    return p*(p-a)*(p-b)*(p-c);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<long, long>> p(n);
    for (int i = 0; i < n; i++) {
        long x, y;
        std::cin >> x >> y;
        p[i] = std::pair<long, long>(x, y);
    }

    double sum = 0;
    long c = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            for (int k = 0; k < j; k++)
                if ((i != j) || (j != k) || (i != k)) {
                    sum += area(p[i], p[j], p[k]);
                    c++;
                }

    std::cout << std::fixed << std::setprecision(10) << sum / (double) c << std::endl;
    return 0;
}