//
// Created by Dmitry Kochetkov on 5/29/2021.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

struct hist_info {
    std::string action;
    long step;
    std::string color;

    hist_info(const std::string &action, long step, const std::string &color) : action(action), step(step),
                                                                                color(color) {};
};

int main() {
    long n;
    std::cin >> n;
    std::string color = "blue";
    bool locked = false;

    std::vector<hist_info> h;

    for (long i = 0; i < n; i++) {
        std::string input;
        std::cin >> input;

        if (input == "lock") {
            locked = true;
            h.push_back(hist_info(input, i+1, color));
        }
        else if (input == "unlock") {
            locked = false;
            h.push_back(hist_info(input, i+1, color));
        }
        else if (!locked) {
            color = input;
            h.push_back(hist_info(color, i+1, color));
        }
    }

    std::cout << color << std::endl;

    long last_lock = -1;
    for (int i = 0; i < h.size(); i++) {
//        std::cout << i.step << " " << i.action << std::endl;
        if (h[i].action == "lock")
            last_lock = i;
    }

    long t;
    std::cin >> t;
    for (long i = 0; i < t; i++) {
        long x;
        std::string msg;

        std::cin >> x;
        std::cin >> msg;

        auto it = std::lower_bound(h.begin(), h.end(), x, [](const hist_info& a, const double& b) {
            return a.step < b;
        });

        long pos = it - h.begin(); // шаг с номером x находится между h[pos] и h[pos+1]
        std::cout << pos << std::endl;

        if (h[pos].step > pos)
            std::cerr << "Weird thing: h[pos].step is not lower bound for pos" << std::endl;

        std::vector<hist_info> new_hist;
        long j = 0;
        for (; h[i].step < x; i++)
            new_hist.push_back(h[i]);

        for ()
        h = new_hist;
    }
    return 0;
}