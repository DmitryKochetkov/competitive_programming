#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count_powers2(long long x) {
    int result = 0;
    while ((x % 2 == 0) && (x > 0)) {
        x = x / 2;
        result += 1;
    }
    return result;
}

int solve(const std::vector<long long>& a) {
    int c = 0; // количество степеней двойки в разложении произведения на простые делители
    vector<int> q(a.size()); // q[i] - количество степеней двойки в индексе i
    int n = a.size();

    for (int i = 0; i < n; i++) {
        c += count_powers2(a[i]);
        q[i] = count_powers2(i+1);
    }

    if (c >= n)
        return 0;

    // увеличить c можно засчет применения уможнения элемента на его индекс
    // операцию имеет смысл производить только с четными индексами
    // нам не важно, к каким именно элементам применяется операция

    sort(q.begin(), q.end(), greater<int>());
    int result = 0;

    for (int i = 0; i < q.size(); i++) {
        c += q[i];
        result += 1;
        if (c >= n)
            return result;
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