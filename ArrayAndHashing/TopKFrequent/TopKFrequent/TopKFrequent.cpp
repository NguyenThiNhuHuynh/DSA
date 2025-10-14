// TopKFrequent.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    //sort 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        vector<pair<int, int>> arr;
        for (const auto& p : count) {
            arr.push_back({ p.second,p.first });
        }
        sort(arr.rbegin(), arr.rend());
        vector <int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(arr[i].second);
        }
        return res;
    }
    //minheap
    vector<int> topKFrequent2(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (const auto& p : count) {
            heap.push({ p.second, p.first });
            if (heap.size() > k) {
                heap.pop();
            }
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
    //bucketsort
    vector<int> topKFrequent3(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto& p : count) {
            bucket[p.second].push_back(p.first);
        }
        vector<int> res;
        for (int i = bucket.size() - 1; i >= 0; --i) {
            for (int num : bucket[i]) {
                res.push_back(num);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    vector<int> nums = { 1, 1, 1, 2, 2, 3, 3, 3, 3 };
    int k = 2;

    vector<int> result = solution.topKFrequent3(nums, k);

    cout << "Các phần tử xuất hiện nhiều nhất là: ";
    for (int num : result) {
        cout << num << " ";
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
