/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int res = 0;
        while (z) {
            // Brian Kernighan 算法, 用来消除最右边的1
            z &= z - 1;  
            ++res;
        }
        return res;
    }

    int hammingDistance2(int x, int y) {
        int z = x ^ y;
        int res = 0;
        while (z) {
            res += z & 1;
            z >>= 1;
        }
        return res;
    }
};
// @lc code=end

