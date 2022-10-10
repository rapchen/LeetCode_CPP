//
// Created by rapch on 2021/12/12.
//
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> diff;
        for (char c : s) {
            if (diff.find(c) == diff.end()) diff[c] = 0;
            diff[c] ++;
        }
        for (char c : t) {
            if (diff.find(c) == diff.end()) diff[c] = 0;
            diff[c] --;
        }
        int res = 0;
        for (auto it: diff) {
            res += abs(it.second);
        }
        return res;
    }
};
