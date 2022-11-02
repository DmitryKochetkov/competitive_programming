//
// Created by Dmitry Kochetkov on 4/10/2021.
//

#include <iostream>
#include <cmath>
#include <iomanip>
long double eps = 1e-12;
using namespace std;
long double a[5];
long double f(long double x) {
    long double x2 = x * x;
    long double x3 = x2 * x;
    long double x4 = x3 * x;
    return a[4] * x4 + a[3] * x3 + a[2] * x2 + a[1] * x + a[0];
}

bool is_out(long double x, long double cx, long double cy, long double cd){
    long double y = f(x);
    if (sqrt((cx-x)*(cx-x)+(cy-y)*(cy-y)) < cd)
        return false;
    else
        return true;
}

long double is_closer(long double x,long double x1, long double cx, long double cy, long double cd){
    long double y = f(x);
    long double y1 = f(x1);
    if (abs(sqrt((cx-x)*(cx-x)+(cy-y)*(cy-y)) - cd) > abs(sqrt((cx-x1)*(cx-x1)+(cy-y1)*(cy-y1)) - cd))
        return x1;
    else
        return x;
}

long double binary_search(long double x, long double cx, long double cy, long double cd) {
    long double l = x;
    long double r = x + 401;
    while (r - l > eps) {
        long double mid = (l + r) / 2.0;
        if (is_out(mid,cx,cy,cd))
            r = mid;
        else
            l = mid;
    }
    long double res = (l + r) / 2.0;
    return res;
    ////////////////////////
    long double l1 = x - 401;
    long double r1 = x;
    while (r1 - l1 > eps) {
        long double mid = (l1 + r1) / 2.0;
        if (is_out(mid,cx,cy,cd))
            r1 = mid;
        else
            l1 = mid;
    }
    long double res1 = (l1 + r1) / 2.0;
    return is_closer(res,res1,cx,cy,cd);
}

int main(){
    long double cx, cy,cd;
    cin >> cx >> cy >> cd;
    int n;
    cin >> n;
    for (int i = n; i >= 0; i--) {
        cin >> a[i];
    }
    long double x;
    cin >> x;
    cout << setprecision(15) << binary_search(x,cx,cy,cd);
}