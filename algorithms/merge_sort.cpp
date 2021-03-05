//
// Created by Dmitry Kochetkov on 3/3/2021.
//

#include <iostream>

void merge(int len, int* a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1+1];
    int right[n2+1];

    for (int i = 0; i < n1; i++)
        left[i] = a[l + i];

    for (int i = 0; i < n2; i++)
        right[i] = a[m + 1 + i];

    left[n1] = INT_MAX;
    right[n2] = INT_MAX;

    int i = 0;
    int j = 0;
    for (int k = l; k <= r; k++)
        if (left[i] < right[j]) {
            a[k] = left[i];
            i++;
        }
        else {
            a[k] = right[j];
            j++;
        }
}

void merge_sort(int len, int* a, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(len, a, l, m);
        merge_sort(len, a, m + 1, r);
        merge(len, a, l, m, r);
    }
}

int main() {
    int n;
    std::cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    merge_sort(n, a, 0, n-1);
    for (int i = 0; i < n; i++)
        std::cout << a[i] << std::endl;

    delete[] a;
    return 0;
}