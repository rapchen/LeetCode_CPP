//
// Created by rapch on 2021/12/12.
//
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> counter;
        for (int num: nums) {
            int s = 0, tmp = num;
            while (tmp > 0) {
                s += tmp % 10;
                tmp /= 10;
            }
            if (counter.find(s) == counter.end()) {
                counter[s] = {num};
            }
            else if (counter[s].size() == 1) {
                counter[s].push_back(min(counter[s][0], num));
                counter[s][0] = max(counter[s][0], num);
            } else {
                counter[s][1] = max(counter[s][1], num);
                if (counter[s][1] > counter[s][0]) {
                    swap(counter[s][0], counter[s][1]);
                }
            }
        }

        int ans = -1;
        for (auto& it: counter) {
            if (it.second.size() >= 2) {
                ans = max(ans, it.second[0] + it.second[1]);
            }
        }
        return ans;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */