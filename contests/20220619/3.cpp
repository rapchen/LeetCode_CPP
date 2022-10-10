//
// Created by rapch on 2021/12/12.
//
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int len = s.size();
        string bin_k = "";
        while (k > 0) {
            bin_k = to_string(k % 2) + bin_k;
            k /= 2;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                string sub = s.substr(i);
                if (sub.size() < bin_k.size() ||
                        (sub.size() == bin_k.size() && sub <= bin_k)) return len;
                len --;
            }
        }
        return len;
    }

};

int main() {
    return 0;
}


//"111100010000011101001110001111000000001011101111111110111000011111011000010101110100110110001111001001011001010011010000011111101001101000000101101001110110000111101011000101"
//11713332
// 96 （113？）