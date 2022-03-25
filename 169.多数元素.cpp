#include <vector>
#include <unordered_map>

using namespace std;
/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:

    // 使用哈希表记录每个元素出现的次数,大于一半就返回.
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); ++i) {
            if (!hash_map.count(nums[i])) hash_map[nums[i]] = 1;
            else hash_map[nums[i]]++;
        }
        int num = 0;
        int res = 0;
        for (auto& var: hash_map) {
            if (var.second > num) res = var.first;
        }
        return res;
    }

    // 投票法
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (int num: nums) {
            if (num == candidate) {
                ++count;
            } else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }

    // 一次判断每个元素数量是否超过一半,超过则返回
    // 平均时间复杂度为线性. 但是某些情况会超时
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums[j] == nums[i]) {
                    ++count;
                }
                if (count > n / 2) return nums[i];
            }
            count = 0;
        }
        return 0;
    }
};
// @lc code=end

