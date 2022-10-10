//
// Created by rapch on 2021/12/12.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        // onetire:一个轮胎跑完i圈需要的最小时间。最多16圈，第17圈>=2^16>10^5
        int onetire[17];
        for (int i = 0; i <= 16; ++i) {
            onetire[i] = 10000000;
        }

        for (auto tire: tires) {
            long lap_time = tire[0];
            long tire_time = 0;
            for (int i = 1; i <= 16; ++i) {
                tire_time += lap_time;
                if (tire_time < onetire[i]) onetire[i] = tire_time;
                lap_time *= tire[1];
                if (lap_time >= 10000000) break;
            }
        }

        int dp[1001];
        for (int i = 1; i <= numLaps; ++i) {
            int res = INT32_MAX;
            for (int j = 1; j <= 16; ++j) {
                if (j == i) {
                    res = min(res, onetire[j]);
                    break;
                }
                res = min(res, onetire[j] + dp[i - j] + changeTime);
            }
            dp[i] = res;
        }
        return dp[numLaps];
    }
};
