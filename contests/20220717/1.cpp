//
// Created by rapch on 2021/12/12.
//
#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num: nums) {
            if (counter.find(num) == counter.end()) counter[num] = 1;
            else counter[num] += 1;
        }
        vector<int> ans = {0,0};
        for (pair<const int, int> it: counter) {
            ans[0] += it.second / 2;
            ans[1] += it.second % 2;
        }
        return ans;
    }
};