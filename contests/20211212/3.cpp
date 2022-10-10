//
// Created by rapch on 2021/12/12.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size(), res = 0;
        int a = capacityA, b = capacityB;
        for (int i = 0; i < n / 2; ++i) {
            if (a < plants[i]) {
                res ++;
                a = capacityA;
            }
            a -= plants[i];
            if (b < plants[n-i-1]) {
                res ++;
                b = capacityB;
            }
            b -= plants[n-i-1];
        }
        if (n % 2 == 1) {
            if (max(a, b) < plants[n / 2]) res ++;
        }
        return res;
    }
};