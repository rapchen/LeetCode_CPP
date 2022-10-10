//
// Created by rapch on 2022/10/9.
//

#include <string>
#include <stack>

using namespace std;class Solution {
public:
    int scoreOfParentheses(string s) {
        int i = 0;
        int scores[50];  // stack
        for (char c: s) {
            if (c == '(') {
                scores[i++] = -1;
            } else {
                int tmp = 0;
                while (i > 0) {
                    int left = scores[--i];
                    if (left == -1) {
                        tmp = tmp == 0 ? 1 : tmp * 2;
                        scores[i++] = tmp;
                        break;
                    } else {
                        tmp += left;
                    }
                }
            }
        }
        int ans = 0;
        while (i > 0) {
            int score = scores[--i];
            ans += score;
        }
        return ans;
    }
};


