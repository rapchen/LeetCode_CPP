//
// Created by rapch on 2021/12/12.
//
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        int a = max(max(amount[0], amount[1]), amount[2]);
        int b = (amount[0] + amount[1] + amount[2] + 1) / 2;
        return max(a, b);

    }
};