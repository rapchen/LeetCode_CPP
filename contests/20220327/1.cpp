//
// Created by rapch on 2021/12/12.
//
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res;
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        res.emplace_back();
        res.emplace_back();
        for (int n: s1) {
            if (s2.find(n) == s2.end()) res[0].emplace_back(n);
        }
        for (int n: s2) {
            if (s1.find(n) == s1.end()) res[1].emplace_back(n);
        }
        return res;
    }
};