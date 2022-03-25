#include <string>
#include <iostream>

using namespace std;
/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        int multiple = 1;
        for (int i = columnTitle.size() - 1; i >= 0; --i) {
            int k = columnTitle[i] - 'A' + 1;
            res += k * multiple;
            multiple *= 26;
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution so;
    cout << so.titleToNumber("ZY") << endl;
}

