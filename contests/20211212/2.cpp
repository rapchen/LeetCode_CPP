//
// Created by rapch on 2021/12/12.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res = 0;

        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int mi = nums[i], ma = nums[i];
            for (int j = i + 1; j < len; ++j) {
                mi = min(mi, nums[j]);
                ma = max(ma, nums[j]);
                res += ma - mi;
            }
        }

        return res;
    }
};