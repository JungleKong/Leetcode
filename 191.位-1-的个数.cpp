#include <cstdint>
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res += n & 1;
            n >>= 1;
        }
        return res;
    }

    int hammingWeight2(uint32_t n) {
        int res = 0;
        while (n) {
            res++;
            n &= n - 1;
        }
        return res;
    }
    // 二分法，每次把剩余的的位数二分成高位部分 跟低位部分，移位后直接相加，
    // 5次二分后最后所有的1都被累加到低6位上，
    int hammingWeight3(uint32_t n) {
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555); 
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333); 
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f); 
        n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff); 
        n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff); 

        return n ; 
    }
};
// @lc code=end

int main() {
    Solution so;
    std::cout << "result:" << so.hammingWeight(543758) << std::endl;

    return 0;
}

