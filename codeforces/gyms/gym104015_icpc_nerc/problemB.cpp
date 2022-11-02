#include <iostream>
#include <cassert>

using namespace std;

bool solve(string s1, string s2) {
    for (int i = 0; i < s1.size(); i++)
        if ((s1[i] == '1') && (s2[i] == '1'))
            return false;
    
    return true;
}

void run_tests() {
    assert(solve("000", "000"));
    assert(!solve("0111", "1110"));
}

int main() {
    // run_tests();
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    if (solve(s1, s2))
        cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}