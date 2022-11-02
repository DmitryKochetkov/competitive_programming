//
// Created by Dmitry Kochetkov on 3/6/2021.
//

#include <bits/stdc++.h>

class time {
public:
    int h;
    int m;
};

bool isCorrectDigit(int c) {
    return (c == 0) || (c == 1) || (c == 2) || (c == 5) || (c == 8);
}

int nextDigit(int digit) {
    if (isCorrectDigit(digit))
        return digit;

    if (digit > 8)
        return 0;
    else if (digit <= 1)
        return digit + 1;
    else if (digit < 5)
        return 5;
    else return 8;
}

int reflection(int digit) {
    if (digit == 0)
        return 0;
    if (digit == 1)
        return 1;
    if (digit == 2)
        return 5;
    if (digit == 8)
        return 8;
    return -1;
}

std::string formatTime(class time t) {
    std::string res = "";
    if (t.h < 10)
        res += "0";
    res += std::to_string(t.h);

    res += ":";

    if (t.m < 10)
        res += "0";
    res += std::to_string(t.m);

    return res;
}

class time closestTime(class time t, int ch, int cm) {
    class time res;

    res.h = nextDigit(t.h / 10) * 10 + nextDigit(t.h % 10);
    res.m = nextDigit(t.m / 10) * 10 + nextDigit(t.m % 10);

    class time r;
    r.h = reflection(res.h / 10) * 10 + reflection(res.h % 10);
    r.m = reflection(res.m / 10) * 10 + reflection(res.m % 10);

    if (r.h >= ch || r.h < 0) {
        res.h = 0;
        res.m = 0;
    }
    else if (r.m >= cm || r.m < 0)
        res.m = 0;

    return res;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int ch, cm;
        std::cin >> ch >> cm;

        std::string arg;
        std::cin >> arg;

        class time time_arg;
        time_arg.h = (arg[0] - '0') * 10 + (arg[1] - '0');
        time_arg.m = (arg[3] - '0') * 10 + (arg[4] - '0');
        class time res = closestTime(time_arg, ch, cm);
        std::cout << formatTime(res) << std::endl;
    }
    return 0;
}
