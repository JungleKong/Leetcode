#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 *
 * [2024] 考试的最大困扰度
 */

// @lc code=start
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return std::max(helper(answerKey, k, 'T'), helper(answerKey, k, 'F'));
    }

    int helper(string& answerKey, int k, char ch) {
        int n = answerKey.size();
        int res = 0;
        for (int i = 0, j = 0, sum = 0; j < n; ++j) {
            sum += answerKey[j] != ch;
            while (sum > k) {
                sum -= answerKey[i++] != ch;
            }
            res = std::max(res, j - i + 1);
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution so;
    std::cout << "result:" << so.maxConsecutiveAnswers("TTFTTFTT", 1) << std::endl;

    return 0;
}
