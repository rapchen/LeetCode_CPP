//
// Created by rapch on 2021/12/12.
//
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int dp[2001] = {0}, ldp[2001] = {0}, n = piles.size();
        int curcum;
        for (int i = 0; i < n; ++i) {
            memcpy(ldp, dp, 2001 * sizeof(int));
            memset(dp, 0, 2001 * sizeof(int));
            curcum = 0;
            for (int j = 0; j <= k; ++j) { // 在第i个pile取j个
                if (j > piles[i].size()) break;
                if (j > 0) curcum += piles[i][j-1];
                for (int m = 0; m <= k - j; m++) { //前面取m个
                    dp[j + m] = max(dp[j+m], ldp[m] + curcum);
                }
            }
        }
        return dp[k];
    }
};
