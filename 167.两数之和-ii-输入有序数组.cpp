#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int temp;
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            temp = numbers[i] + numbers[j];
            if (temp == target) return {i + 1, j + 1};
            else if (temp > target) --j;
            else ++i;
        }
        return {0, 0};
    }
};
// @lc code=end

