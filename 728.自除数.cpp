#include "include/utils.h"
/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 */

// @lc code=start
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; ++i) {
            string str = to_string(i);
            for (int j = 0; j < str.size(); ++j) {
                int val = str[j] - '0';
                if (val == 0 || i % val != 0) 
                    break;
                else if (j == str.size() - 1)
                    res.push_back(i);
            } 
        }
        return res;
    }
};

int main() {
    Solution so;
    printVec(so.selfDividingNumbers(47, 85));
    return 0;
}
// @lc code=end

