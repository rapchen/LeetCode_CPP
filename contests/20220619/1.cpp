//
// Created by rapch on 2021/12/12.
//
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        bool a[26] = {false}, b[26] = {false};
        string ans = "";
        for (char c: s) {
            if ('a' <= c && c <= 'z') {
                b[c - 'a'] = true;
            } else if ('A' <= c && c <= 'Z') {
                a[c - 'A'] = true;
            }
        }
        for (int i = 25; i >= 0; --i) {
            if (a[i] && b[i]) {
                ans = (char)(i + 'A');
                return ans;
            }
        }
        return "";
    }
};