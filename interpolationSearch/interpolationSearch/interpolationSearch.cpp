// interpolationSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int interpolationSearch(int a[], int n, int x) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) * (x-a[left])/(a[right]-a[left]);
        if (x == a[mid]) {
            return mid;
        }
        if (x < a[mid]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int a[] = { 2, 3, 5, 7, 9, 12, 15 };
    int n = sizeof(a) / sizeof(a[0]);
    int x;

    cout << "Nhap gia tri can tim: ";
    cin >> x;
    int result = interpolationSearch(a, n, x);
    if (result != -1) {
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
