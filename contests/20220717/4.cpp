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
    inline int gcd(int a, int b) {
        return b > 0 ? gcd(b, a % b) : a;
    }

    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        // 找到最大公约数
        int ngcd = numsDivide[0];
        for (int i = 1; i < numsDivide.size(); ++i) {
            ngcd = gcd(ngcd, numsDivide[i]);
        }

        // ans
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > ngcd) return -1;
            if (ngcd % nums[i] == 0) return i;
        }
        return -1;
    }
};



//10
//11
//91997497

//9767
//9557

9559
9581
