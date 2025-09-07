// MaxProduct.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <climits> 
using namespace std;

int maxProduct(int a[], int n) {
    int count_0 = 0, count_neg = 0;
    int max_neg = INT_MIN;
    int product = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            count_0++;
            continue;
        }
        product *= a[i];
        if (a[i] < 0) {
            count_neg++;
            max_neg = max(max_neg, a[i]);
        }
    }
    if (count_0 == n || (count_neg == 1 && count_0 == n - 1)) {
        return 0;
    }
    if (count_neg % 2 == 1) {
        product /= max_neg;
    }
    return product;
}

int main()
{
    int a[] = { -1, -3, 4, 0, 3 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Max product = " << maxProduct(a, n) << endl;
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
