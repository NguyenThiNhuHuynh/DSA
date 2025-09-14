// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void quickSort(int a[], int low, int high) {
    if (low >= high) return; 
    int pivot = a[high];     
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);   
    int pi = i + 1;
    quickSort(a, low, pi - 1);  
    quickSort(a, pi + 1, high); 
}


int main()
{
	int a = 5;
	int* p = &a;
	printf("Gia tri cua a: %d\n", a);
	printf("Dia chi cua a: %p\n", p);
	printf("Gia tri qua con tro: %d\n", *p);
	*p = 10;  
	printf("Gia tri cua a sau khi thay doi: %d\n", a);

    int b[] = { 9, 3, 7, 6, 2, 8 };
    int n = 6;
    quickSort(b, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
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
