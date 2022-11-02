#include <iostream>
#include <cassert>

using namespace std;

double solve(double x, double y) {
    if ((y - x <= 0) && (y/2 <= x/4))
        return -1;

    

    return min(min(2*y, x/2+y), y/2 + x);
}

void run_tests() {
    assert(solve(10, 15) == 20.0);
    assert(solve(6, 4) == 7.0);
    assert(solve(10, 2) == -1);
    assert(solve(7, 4) == 7.5);
    assert(solve(7, 4) == 7.5);
    assert(solve(500000000, 1000000000) == 1250000000.0)
}

int main() {
    // run_tests();
    double x, y;
    cin >> x >> y;

    // Обозначим стороны прмяоугольника a > b
    // p = 2(a+b)

    // Варианты для прямоугольника со сторонами a и b
    // x = 2*a либо x = a + b либо x = 2*b
    // y = 2*a + b либо y = 2*b + a


    // x = 2*a, y = 2*a + b => a = x / 2, b = y - 2 * a = y - x => 2(a+b) = x + 2(y-x) = 2*y
    // x = 2*a, y=2*b + a => a = x / 2, b = (y-a)/2 = (y-x/2)/2 = y/2 - x/4 => 2(a+b) = x + y - x/2 = x/2 + y
    // x = a+b, y = 2*a + b = a + a + b => p = 2*x. 
    // x = 2*b, y=2*a+b. => b = x / 2, a = x/2 - y/4

    // Варианты: y = x+a либо x = x+b
    // x = 2*a либо x = a + b либо x = 2*b

    // x = 2*a

    cout << solve(x, y) << endl;
    return 0;
}