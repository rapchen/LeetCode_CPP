//
// Created by rapch on 2021/12/12.
//
#include <vector>
#include <set>

using namespace std;

class SmallestInfiniteSet {
public:
    int smallest = 1;
    set<int> nums = {};

    SmallestInfiniteSet() {
        smallest = 1;
        nums.clear();
    }

    int popSmallest() {
        if (nums.empty()) {
            smallest += 1;
            return smallest - 1;
        } else {
            int ans = *nums.begin();
            nums.erase(nums.begin());
            return ans;
        }
    }

    void addBack(int num) {
        if (num < smallest) {
            nums.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */