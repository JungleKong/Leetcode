#include <string>
#include <iostream>

using namespace std;
/*
 * @lc app=leetcode.cn id=2038 lang=cpp
 *
 * [2038] 如果相邻两个颜色均相同则删除当前颜色
 */

// @lc code=start
class Solution {
public:
    bool winnerOfGame(string colors) {
        int A = 0, B = 0;
        for (int i = 1; i < colors.size() - 1; ++i) {
            if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A')
                ++A;
        }
        for (int i = 1; i < colors.size() - 1; ++i) {
            if (colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B')
                ++B;
        }
        if (A > B) return true;
        return false;
    }
};
// @lc code=end

