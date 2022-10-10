//
// Created by rapch on 2021/12/12.
//
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        vector<int> deleted;
        int res;
        for (int n: nums) {
            if (deleted.size() % 2 == 0 || deleted.back() != n) {
                deleted.push_back(n);
            } else {
                res ++;
            }
        }
        if (deleted.size() % 2 != 0) res ++;
        return res;
    }
};
