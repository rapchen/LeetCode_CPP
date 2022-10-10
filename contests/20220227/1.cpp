//
// Created by rapch on 2021/12/12.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for (const string& word: words) {
            if (word.find(pref) == 0) {
                res ++;
            }
        }
        return res;
    }
};
