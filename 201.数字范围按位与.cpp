#include "include/utils.h"
 /**
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
    // 5: 0101
    // 6: 0110
    // 7: 0111
    // 8: 1000
    // 9: 1001
    // 如果最高位不同的话, 结果一定为0..等驾驭找最高位有几位相同
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shift += 1;
        }
        return left << shift;
    }
    

};
// @lc code=end

int main() {
    Solution so;
    cout << so.rangeBitwiseAnd(5, 12) << endl;
    return 0;
}
