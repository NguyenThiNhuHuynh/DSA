// VetCan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int linearSearch(int a[], int n, int x) {
    for (int pos = 0; pos < n; pos++) {
        if (a[pos] == x) {
            return pos;
        }
    }
    return -1;
}

int main()
{
    int a[] = { 5, 3, 7, 2, 9 };
    int n = sizeof(a) / sizeof(a[0]);
    int x;

    cout << "Nhap gia tri can tim: ";
    cin >> x;
    int result = linearSearch(a, n, x);
    if (result != 1) {
        cout << "Tim thay " << x << " o vi tri " << result << endl;
    }
    else {
        cout << "Khong tim thay " << x;
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
