// CountingSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


void countingSort(int a[], int n, int c[]) {
    int maxValue = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > maxValue) maxValue = a[i];
    }
    int MAX = maxValue + 1;

    int* b = new int[MAX](); 

    for (int i = 0; i < n; i++) {
        b[a[i]]++;
    }
    for (int i = 1; i < MAX; i++) {
        b[i] += b[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        b[a[i]]--;
        c[b[a[i]]] = a[i];
    }
    delete[] b;
}

int main()
{
    int a[] = { 4, 2, 2, 8, 3, 3, 1 };
    int n = sizeof(a) / sizeof(a[0]);
    int* c = new int[n];

    countingSort(a, n, c);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
