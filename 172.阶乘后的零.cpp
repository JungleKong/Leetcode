/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    // 直接统计5的个数即可
    int trailingZeroes(int n) {
        int count = 0;
        while (n > 4) {
            count += n / 5;
            n /= 5;
        }
        return count;
    }
};
// @lc code=end

