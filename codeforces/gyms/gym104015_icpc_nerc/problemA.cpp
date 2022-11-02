#include <iostream>

using namespace std;

int solve(int n, int a, int b) {
    // minimize n-(a*x+b*y) w.r.t. a * x + b * y <= n, x < y
    // maximize (a*x+b*y) w.r.t. a * x + b * y <= n, x < y

    int opt_x = 1; // количество конфет, которые раздали мальчикам
    int opt_y = 2; // количество конфет, которые раздали девочкам
    int answer = a + b * 2;

    for (int x = n; x >= 1; x--)
        for (int y = n; y >= 1; y--)
            if ((a * x + b * y <= n) && (x < y) && (a*x + b*y > answer)) {
                opt_x = x;
                opt_y = y;
                answer = a * opt_x + b * opt_y;
            }

    return n - answer;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    cout << solve(n, a, b) << endl;
    return 0;
}