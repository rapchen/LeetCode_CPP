//
// Created by rapch on 2021/12/12.
//
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int v_len = (intLength + 1) / 2;
        long long min_ = 1, a, i;
        for (i = 1; i < v_len; i++) min_ *= 10;
        long long max_ = min_ * 10 - 1;
        vector<long long> res;
        char tmp[16];
        tmp[intLength] = '\0';
        for (int q: queries) {
            a = min_ - 1 + q;
            if (a > max_) {
                res.emplace_back(-1);
                continue;
            }
            sprintf(tmp, "%ld", a);
            for (i = intLength - v_len -1; i >= 0; i--) {
                a = a * 10 + (tmp[i] - 48);
            }
            res.emplace_back(a);
        }
        return res;
    }
};
