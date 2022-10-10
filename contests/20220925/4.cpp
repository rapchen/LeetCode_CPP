//
// Created by rapch on 2022/9/25.
//


#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;


class TNode {
public:
    int val;
    TNode* father;
    vector<TNode*> sons;
    unordered_map<int, int> paths;  // <val, cnt>
    TNode(int val, TNode* father) {
        this->val = val;
        this->father = father;
    }
};

class Solution {
public:
    int good_path(TNode* node) {
        int res = 1;  // 自环
        node->paths[node->val] += 1;

        for (TNode* son: node->sons) {
            if (son == node->father) continue;
            res += good_path(son);  // 累计下面已经完成的数量
            for (auto& it: son->paths) {
                if (it.first >= node->val && it.second > 0) {   // 不大于，就可以把son的路径连过来
                    res += it.second * node->paths[it.first];  // 左边或者node跟son的成功路径数
                    node->paths[it.first] += it.second;  // 更新，准备往上连
                }
            }
        }
        return res;
    }

    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        // 就取0作为根，构造树
        vector<TNode> nodes;
        nodes.reserve(vals.size());
        for (int val: vals) {
            nodes.emplace_back(val, nullptr);
        }
        for (auto& edge: edges) {
            int p = edge[0], q = edge[1];
            nodes[p].sons.push_back(&nodes[q]);
            nodes[q].sons.push_back(&nodes[p]);
        }
        unordered_set<TNode*> in_tree;
        deque<TNode*> ready_push;
        ready_push.push_back(&nodes[0]);
        while (!ready_push.empty()) {
            TNode* p = ready_push.front();
            ready_push.pop_front();
            in_tree.insert(p);

            for (TNode* q: p->sons) {
                if (in_tree.find(q) == in_tree.end()) {
                    q->father = p;
                    ready_push.push_back(q);
                }
            }
        }

        // 开找
        return good_path(&nodes[0]);
    }
};

int main(){
    vector<int> vals{1,3,2,1,3};
    vector<vector<int>> edges{{0, 1}, {0, 2}, {2, 3}, {2, 4}};
    int a = Solution().numberOfGoodPaths(vals, edges);
    a= a;
}
