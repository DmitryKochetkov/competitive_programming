#include <iostream>
#include <random>
#include <cassert>
#include <time.h>

#define assertm(exp, msg) assert(((void)msg, exp))

using namespace std;

pair<int, int> solve_brute_force(int a, int b, int c, int d) {
    for (int x = a+1; x <= c; x++)
        for (int y = b+1; y <= d; y++)
            if ((x * y) % (a * b) == 0)
                return pair<int, int>(x, y);

    return pair<int, int>(-1, -1);            
}

pair<int, int> solve_brute_force2(int a, int b, int c, int d) {
    for (int x = a+1; x <= c; x++)
        for (int y = b+1; y <= d; y++)
            if ((x * y) % (a * b) == 0)
                return pair<int, int>(x, y);

    return pair<int, int>(-1, -1);            
}

pair<int, int> solve(int a, int b, int c, int d) {
    // проще действовать в предположении, что a <= b
    if (b > a) {
        swap(a, b);
        swap(c, d);
    }

    // если a <= b, то a^2 <= a * b
    // Если мы ищем x, который был бы больше a и при этом делился бы на a*b, то 

    // Первая идея, которая приходит в голову - сделать как с диофантовыми уравнениями
    // найти базовое решение - любую пару x * y
    // затем как-то перебирать решения
    int x = 2 * a;
    int y = 2 * b;

    vector<pair<int, int>> possible_solutions = {
        pair<int, int>(2*a, 2*b),
        pair<int, int>(2*b, a),
        pair<int, int>(b, 2*a),
    };
    
    for (auto solution: possible_solutions) {
        if ((solution.first <= c) && (solution.first > a) && (solution.second <= d) && (solution.second > b))
            return pair<int, int>(-1, -1);
    }

    return pair<int, int>(-1, -1);   
}

void random_test() {    
    int a = rand() % 1000 + 1;
    int b = rand() % 1000 + 1;
    int c = rand() % 1000 + 1;
    int d = rand() % 1000 + 1;

    // cout << a << " " << b << " " << c << " " << d << endl;

    assertm(solve(a, b, c, d) == solve_brute_force(a, b, c, d), "Tests failed");
}

void run_tests(int test_count) {
    while (test_count--)
        random_test();
    cout << "Tests passed" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        pair<int, int> solution = solve(a, b, c, d);
        cout << solution.first << " " << solution.second << endl;
    }
    return 0;
}