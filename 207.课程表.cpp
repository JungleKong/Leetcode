/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> yes;
        unordered_map<int, int> no;
        for (auto& pre: prerequisites) {
            if (pre[0] > pre[1])  
                yes.insert(pre[0]);  // 依赖其他课程才能学习的课程，单纯的这样判断有问题，
            else 
                no[pre[0]] = pre[1];  // 暂时无法学习的课程
        }
        for(int i = 0; i < numCourses; ++i) {
            if (no.find(i) == no.end()) {  // 找到不依赖其他课程就能学习的课程，会与前面重复
                yes.insert(i);
            }
        }
        
        while (no.size() != 0) {
            int preSize = no.size();
            for (auto& n: no) {
                if (yes.find(n.second) != yes.end()) {
                    yes.insert(n.first);
                    no.erase(n.first);
                    if (no.size() == 0) break;
                }
            }
            if (preSize == no.size()) return false;
        }
        return true;
    }

private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;

public:
    void dfs(int u) {
        visited[u] = 1;
        for (int v: edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;
    }

    bool canFinish2(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        return valid;
    }
};
// @lc code=end
int main() {
    Solution so;
    vector<vector<int>> pres = {{1, 0}, {0, 1}};
    cout << so.canFinish(2, pres) << endl;
    return 0;
}
