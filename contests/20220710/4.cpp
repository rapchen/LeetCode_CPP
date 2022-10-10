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
    int idealArrays(int n, int maxValue) {
        int factors[10001] = {0}, factor_size = 1, fac;
        factors[0] = 1;
        for (int p = maxValue; p >= 1; --p) {
            fac = maxValue / p;
            if (fac == factors[factor_size - 1]) continue;
            factors[factor_size] = fac;
            factor_size ++;
        }

            // dp[i][j]: n=i, max=j的种类数
        int dp[10001]= {0}, new_dp[10001] = {0};
        for (int j = 1; j <= maxValue; ++j) dp[j] = j;
        for (int i = 2; i <= n; ++i) {
            for (int t = 0; t < factor_size; ++t) {
                int j = factors[t];

                new_dp[j] = new_dp[j/2];
                // 第一个数取k， 有dp[i-1][j//k]种
                for (int k = 1; k <= j; k += 2) {
                    new_dp[j] = (new_dp[j] + dp[j / k]) % 1000000007;
                }
            }
            memcpy(dp, new_dp, sizeof(int) * 10001);
        }

        return (int)(dp[maxValue] % 1000000007);
    }
};

int main(){
    int a = Solution().idealArrays(10000,10000);
    a = a+1;
}


//10
//11
//91997497

//9767
//9557

9559
9581
