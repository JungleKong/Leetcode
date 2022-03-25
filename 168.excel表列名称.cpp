#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while (columnNumber > 0) {
            columnNumber--;
            int temp = columnNumber % 26;
            columnNumber /= 26;
            res += (char)(temp + 'A');
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

int main() {
    Solution so;
    cout << so.convertToTitle(701) << endl;
}
