// ProductOfArrayExceptSelf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public: 
    //bruteforce
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i++) {
            int prod = 1;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    prod *= nums[j];
                }
            }
            res.push_back(prod);
        }
        return res;
    }
    //division
    vector<int> productExceptSelf2(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int zeroCount = 0;
        int total = 1;
        for (int num : nums) {
            if (num == 0) {
                zeroCount++;
            }
            else {
                total *= num;
            }

        }
        for (int i = 0; i < n; i++) {
            if (zeroCount > 1) {
                res.push_back(0);
            }
            else if (zeroCount == 1) {
                if (nums[i] == 0) {
                    res.push_back(total);
                }
                else {
                    res.push_back(0);
                }
            }
            else {
                res.push_back(total / nums[i]);
            }
        }
        return res;
    }
};

int main() {
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    vector<int> result = sol.productExceptSelf2(nums);

    cout << "Ket qua: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

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
