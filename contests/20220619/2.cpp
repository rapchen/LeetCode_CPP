//
// Created by rapch on 2021/12/12.
//
#include <vector>

using namespace std;

class Solution {
public:
    int minimumNumbers(int num, int k) {
        int multi;
        if (num == 0) return 0;
        for (int i = 1; i <= 10; ++i) {
            multi = k * i;
            if (multi % 10 == num % 10 && num >= multi) return i;
        }
        return -1;
    }
};
