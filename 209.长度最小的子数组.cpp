/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        return minSubArrayLen2(target, nums);
    }
    int minSubArrayLen1(int target, vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (target > sum) return 0;
        // 滑动窗口
        int res = nums.size();
        sum = 0;
        int start = 0, end = 0;
        while (end < nums.size()) {
            sum += nums[end];
            while (sum >= target) {
                res = min(res, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return res;
    }

    // 暴力法, 可以构造前缀和列表，利用二分查找降低时间复杂度
    int minSubArrayLen2(int target, vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (target > sum) return 0;

        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum >= target) {
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

