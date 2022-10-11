//
// Created by rapch on 2022/10/10.
//

#include <vector>

using namespace std;

class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int dp[4] = {nums1[0], nums2[0], 0, 1};  // 存当前的nums1末尾，nums2末尾以及正、反对应的操作次数（分别考虑两种末尾）
        int n = nums1.size();
        for (int i = 1; i < n; ++i) {
            int res1 = 10000000;  // 这两位正存，MAX_INT
            int res2 = 10000000;  // 这两位反存，MAX_INT
            if (nums1[i] > dp[0] && nums2[i] > dp[1]) {
                res1 = min(res1, dp[2]);
                res2 = min(res2, dp[3] + 1);
            }
            if (nums1[i] > dp[1] && nums2[i] > dp[0]) {
                res1 = min(res1, dp[3]);
                res2 = min(res2, dp[2] + 1);
            }
            dp[0] = nums1[i];
            dp[1] = nums2[i];
            dp[2] = res1;
            dp[3] = res2;
        }
        return min(dp[2], dp[3]);
    }
};
