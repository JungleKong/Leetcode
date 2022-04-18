#include "include/utils.h"

/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> hash_set;
        hash_set.insert(n);
        while (true) {
            int happy = helper(n);
            if (happy == 1) 
                return true;
            if (hash_set.find(happy) != hash_set.end()) 
                return false;
            n = happy;
            hash_set.insert(happy);
        }
        return false;
    }

    int helper(int n) {
        int res = 0;
        while (n > 0) {
            res += pow(n % 10, 2);
            n /= 10;
        }
        return res;
    }

    // 快慢指针法. 有循环最终会相遇.没有循环快指针最先到达1
    bool isHappy1cd (int n) {
        int slow = n;
        int fast = helper(n);
        while (fast != 1 && slow != fast) {
            slow = helper(slow);
            fast = helper(helper(fast));
        }
        return fast == 1;
    }
};
// @lc code=end

int main() {
    Solution so;
    so.isHappy(19);
}
