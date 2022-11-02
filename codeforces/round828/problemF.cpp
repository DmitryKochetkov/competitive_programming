#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(const std::vector<long long>& a) {
    int c = 0; // количество степеней двойки в разложении произведения на простые делители
    
    for (int i = 0; i < a.size(); i++) {
        
    }

    return -1;
}

int main() {
    int t;
    
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << solve(a) << endl;
    }
    return 0;
}