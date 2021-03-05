//
// Created by Dmitry Kochetkov on 3/3/2021.
//

#include <iostream>

void insertion_sort(int len, int* a) {
    for (int i = 1; i < len; i++) {
        int key = a[i];
        int j = i-1; //
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main() {
    int n;
    std::cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    insertion_sort(n, a);
    for (int i = 0; i < n; i++)
        std::cout << a[i] << std::endl;

    delete[] a;
    return 0;
}