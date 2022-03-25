#include <string>
#include <set>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 */

// @lc code=start
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        k--;
        while (k > 0) {
            long long left = cur;  // 当前节点
            long long right = cur + 1;  // 相当与右侧相邻的兄弟节点
            int node_num = 0;
            while (left <= n) {  // 当前树的节点数量
                // 当前层的节点数量
                node_num += min(right, (long long)(n + 1)) - left;
                left *= 10;
                right *= 10;
            }
            if (k >= node_num) {  // 当前树的节点数量大于K
                k -= node_num;
                cur++;
            } else {  // 在当前子树,遍历查找
                k--;
                cur *= 10;
            }
        }
        return cur;
    }

    int findKthNumber2(int n, int k) {
        set<string> s;
        for (int i = 1; i <= n; ++i) {
            s.insert(to_string(i));
        }
        vector<string> v(s.begin(), s.end());
        return atoi(v[k].c_str());
    }
};
// @lc code=end

int main() {
    Solution so;
    cout << so.findKthNumber(1234, 55) << endl;
    return 0;
}
