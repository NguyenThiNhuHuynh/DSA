// GroupAnagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    //sort
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& pair : groups) {
            result.push_back(pair.second);
        }
        return result;
    }
    //hashtable
    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key;
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]) + "#";
            }
            mp[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& pair : mp) {
            result.push_back(pair.second);
        }
        return result;
    }

};

int main() {
    Solution solution;
    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };

    vector<vector<string>> result = solution.groupAnagrams2(strs);

    cout << "[\n";
    for (auto& group : result) {
        cout << "  [";
        for (int i = 0; i < group.size(); i++) {
            cout << "\"" << group[i] << "\"";
            if (i < group.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    cout << "]\n";

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
