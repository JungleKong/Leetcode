/*
 * @lc app=leetcode.cn id=1672 lang=cpp
 *
 * [1672] 最富有客户的资产总量
 */
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = -1;
        for (int i = 0; i < accounts.size(); ++i) {
            res = max(std::accumulate(accounts[i].begin(), accounts[i].end(), 0), res);
        }
        return res;
    }
};
// @lc code=end

