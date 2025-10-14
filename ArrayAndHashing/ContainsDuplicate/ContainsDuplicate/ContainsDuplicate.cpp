#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    //brute force
    bool hasDuplicate1(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }

    //sort 
    bool hasDuplicate2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }

    //hash set
    bool hasDuplicate3(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) return true;
            seen.insert(num);
        }
        return false;
    }
};

int main() {
    Solution solution;

    int n;
    cout << "Nhap so phan tu: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (solution.hasDuplicate3(nums))
        cout << "Co phan tu trung lap\n";
    else
        cout << "Khong co phan tu trung lap\n";

    return 0;
}
