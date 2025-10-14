#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //brute force
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return { i, j }; 
                }
            }
        }
        return {}; 
    }

    //sorting
    vector<int> twoSum2(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({ nums[i],i });
        }
        sort(arr.begin(), arr.end());
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int sum = arr[left].first + arr[right].first;
            if (sum == target) {
                int n1 = arr[left].second;
                int n2 = arr[right].second;
                if (n1 > n2) { swap(n1, n2); }
                return { n1,n2 };
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        return {};

    }

    //hashmap
    vector<int> twoSum3(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> seen;
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (seen.count(complement)) {
                return { seen[complement],i };
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;

    vector<int> result = solution.twoSum3(nums, target);

    if (!result.empty()) {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    }
    else {
        cout << "Khong tim thay cap phu hop." << endl;
    }

    return 0;
}
