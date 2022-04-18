/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        int i = 0;
        int cur = 1;
        while (true) {
            long long left = cur;
            long long right = cur + 1;
            int node_num = 0;
            while (left <= n) {
                node_num += min(right, (long long)(n + 1)) - left;
                left *= 10;
                right *= 10;
            }
            if (n >= node_num) {
                n -= node_num;
                cur++;
            }
        }
    }
};
// @lc code=end

