//
// Created by Dmitry Kochetkov on 4/11/2021.
//

#include <bits/stdc++.h>

// Binary search (note boundaries in the caller)
int CeilIndex(std::vector<long>& v, int l, int r, int key)
{
    while (r - l > 1) {
        long m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

int LongestIncreasingSubsequenceLength(std::vector<long>& v)
{
    if (v.size() == 0)
        return 0;

    std::vector<long> tail(v.size(), 0);
    long length = 1; // always points empty slot in tail

    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {

        // new smallest value
        if (v[i] < tail[0])
            tail[0] = v[i];

            // v[i] extends largest subsequence
        else if (v[i] > tail[length - 1])
            tail[length++] = v[i];

            // v[i] will become end candidate of an existing
            // subsequence or Throw away larger elements in all
            // LIS, to make room for upcoming grater elements
            // than v[i] (and also, v[i] would have already
            // appeared in one of LIS, identify the location
            // and replace it)
        else
            tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
    }

    return length;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), dp(n);

    dp[n-1] = 1;
    for (int i = n-2; i >= 0; i--) {
        
    }

    for (auto x: dp)
        std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}