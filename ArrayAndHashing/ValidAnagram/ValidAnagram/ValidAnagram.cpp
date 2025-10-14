#include <iostream>
#include <algorithm> 
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    //sort
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    //hashmap
    bool isAnagram1(string s, string t) {
        if (s.length() != t.length()) return false;
       // unordered_map<char, int> count;
       // for (char c : s) {
       //     count[c]++;
       // }
       // for (char c : t) {
       //     count[c]--;
       // }
       // for (auto c : count) {
       //     if (c.second != 0)
       //         return false;
       // }
       // return true;

        unordered_map<char, int> countS;
        unordered_map<char, int> countT;
        for (char c : s) {
            countS[c]++;
        }
        for (char c : t) {
            countT[c]++;
        }
        if (countS == countT) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    string s, t;

    cout << "Nhap chuoi s: ";
    cin >> s;
    cout << "Nhap chuoi t: ";
    cin >> t;

    if (solution.isAnagram1(s, t))
        cout << "Hai chuoi la anagram\n";
    else
        cout << "Hai chuoi khong phai anagram\n";

    return 0;
}
