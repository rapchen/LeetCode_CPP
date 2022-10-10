//
// Created by rapch on 2021/12/12.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        int n = rings.length() / 2;
        int res[10] = {0};
        char tmp = '\0';
        for (const char c : rings) {
            if (tmp == '\0') tmp = c;
            else {
                int pos = c - 48;
                if (tmp == 'R') res[pos] |= 1;
                else if (tmp == 'G') res[pos] |= 2;
                else if (tmp == 'B') res[pos] |= 4;
                tmp = '\0';
            }
        }
        int final = 0;
        for (int re : res) {
            if (re == 7) final ++;
        }
        return final;
    }
};
