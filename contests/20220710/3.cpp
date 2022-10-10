//
// Created by rapch on 2021/12/12.
//
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (i<n && start[i] == '_') i++;
            while (j<n && target[j] == '_') j++;
            if (i == n && j == n) return true;
            if (i == n || j == n) return false;
            if (start[i] != target[j]) return false; // can't change order
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;

            i++; j++;
        }
        return true;
    }
};

int main() {
    return 0;
}


//"111100010000011101001110001111000000001011101111111110111000011111011000010101110100110110001111001001011001010011010000011111101001101000000101101001110110000111101011000101"
//11713332
// 96 （113？）