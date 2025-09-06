#include <iostream>
using namespace std;

int binarySearch(int a[], int n, int x) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
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
    int result = binarySearch(a, n, x);
    if (result != -1) {
        cout << "Tim thay " << x << " o vi tri " << result << endl;
    }
    else {
        cout << "Khong tim thay " << x;
    }
    return 0;
}
