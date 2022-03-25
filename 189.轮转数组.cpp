#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    // [1,2,3,4,5,6,7]
    // [7,6,5,4,3,2,1]
    // [5,6,7,4,3,2,1]
    // [5,6,7,1,2,3,4]
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();  // if n > nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }


    // 很遗憾,超时
    void rotate1(vector<int>& nums, int k) {
        for (int i = 0; i < k; ++i) {
            rotateRight(nums);
        }
    }

    void rotateRight(vector<int>& nums) {
        for (int i = nums.size() - 1; i > 0; --i) {
            swap(nums[i], nums[i - 1]);
        }
    }
};

int main() {
    Solution so;
    vector<int> v = {1,2,3,4,5,6,7};
    so.rotate(v, 7);
    for (int i: v) {
        cout << i << " ";
    }
    cout << endl;
}
// @lc code=end

