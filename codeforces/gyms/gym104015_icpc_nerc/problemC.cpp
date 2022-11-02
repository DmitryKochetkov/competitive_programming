#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

bool solve(const vector<vector<int>>& a) {
    vector<int> s(a.size(), 0); // s[i] - количество студентов, которым удобно ходить в i-й день 
    // vector<vector<int>> p(a.size(), ) // p[i][j] - количество студентов, которым удобно ходить и в i-й день, и в j-й день
    
    for (int j = 0; j < 5; j++)
        for (int i = 0; i < a.size(); i++)
            s[j] += a[i][j];

    for (int i = 0; i < 5; i++)
        for (int j = i+1; j < 5; j++)
            if ((s[i] + s[j] == a.size()) && (s[i] > 0) && (s[i] == s[j]))
                return true;
    
    return false;
}

// void run_tests() {
//     assert(solve("000", "000"));
//     assert(!solve("0111", "1110"));
// }

int main() {
    // run_tests();
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(5, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            cin >> a[i][j];

    if (solve(a))
        cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}