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
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        long long dp[201][201] = {0};
        for (vector<int> item: prices) {
            dp[item[0]][item[1]] = item[2];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                for (int k = 1; k < i; ++k) {
                    dp[i][j] = max(dp[i][j], dp[k][j] + dp[i-k][j]);
                }
                for (int k = 1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j-k]);
                }
            }
        }
        return dp[m][n];
    }
};
