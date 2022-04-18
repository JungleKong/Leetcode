/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;


// @lc code=start
class Solution {
public:
    unordered_set<string> ans;
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;  // 左括号 右括号需要删除的数量
        for (auto c: s) {
            if (c == '(') {
                l++;
            } else if (c == ')') {
                if (l <= 0) r++;
                else l--;
            }
        }
        dfs(s, 0, "", 0, l, r);
        // backTrack(s, 0, l, r);
        return vector<string>(ans.begin(), ans.end());
    }

    // BFS
    // 感觉就是暴力解法
    // 删除一个括号，判断，不行就删除两个再判断
    vector<string> removeInvalidParentheses2(string s) {
        vector<string> ans;
        unordered_set<string> currSet;

        currSet.insert(s);
        while(true) {
            // 判断当前是否有满足的情况
            for (auto& str: currSet) {
                if (isValid(str)) {
                    ans.push_back(str);
                }
            }
            if (ans.size() > 0) return ans;
            
            // 删除更多一个括号
            unordered_set<string> nextSet;
            for (auto& str: currSet) {
                for (int i = 0; i < str.size(); ++i) {
                    if (i > 0 && str[i] == str[i - 1]) continue;  // 连续括号的情况

                    if (str[i] == '(' || str[i] == ')') {
                        nextSet.insert(str.substr(0, i) + str.substr(i + 1));
                    }
                }
            }
            currSet = nextSet;
        }
    }

    void dfs(string& s, int u, string res, int cnt, int l, int r) {
        if (u == s.size()) {
            if (cnt == 0) // cnt==0表示当前字符串res左右括号相等
                ans.insert(res);
            return;
        }

        if (s[u] == '(') {
            dfs(s, u + 1, res + '(', cnt + 1, l, r);  // 不删,
            if (l > 0) // 可以删除一个左括号
                dfs(s, u + 1, res, cnt, l - 1, r);
        } else if (s[u] == ')') {
            if (cnt > 0)  // 只有当前cnt > 0, 也就是res中左括号比右括号多的时候，才可以选择不删。否则前面的括号就不平衡了
                dfs(s, u + 1, res + ')', cnt - 1, l, r);
            if (r > 0) // 可以删除一个右括号
                dfs(s, u + 1, res, cnt, l, r - 1);
        } else {  // 当前字符串是字母
            dfs(s, u + 1, res + s[u], cnt, l, r);
        }
    }

    void dfs(string& s, int u, string res, int cnt, int l, int r) {
        if (u == s.size()) {
            if (cnt == 0) // cnt==0表示当前字符串res左右括号相等
                ans.insert(res);
            return;
        }

        if (s[u] == '(') {  //对于连续的k个'(' 只需考虑一次性 删 i个(0<=i<=k) 则可从2^k降到 k
            int k = u;
            while (k < s.size() && s[k] == '(') k++;
            l -= k - u;
            for (int i = k - u; i >= 0; i--) {  // 从删除一个一直到删除k个，如果可能的话
                if (l >= 0) dfs(s, k, res, cnt, l, r);
                res += '(', cnt++, l++;
            }
        } else if (s[u] == ')') {
            int k = u;
            while (k < s.size() && s[k] == ')') k ++;//找到最后一个连续的')'的右边
            r -= k - u;//假设将这些连续的')'全部删除
            for (int i = k - u; i >= 0; i -- ) {//i为删除的长度
                if (cnt >= 0 && r >= 0) dfs(s, k, res, cnt, l, r);//可删时
                res += ')', cnt--, r++;
            }
        } else {  // 当前字符串是字母
            dfs(s, u + 1, res + s[u], cnt, l, r);
        }
    }

    void backTrack(string s, int start, int lremove, int rremove) {
        if (lremove == 0 && rremove == 0) {
            if (isValid(s)) {
                ans.insert(s);
            }
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (i != start && s[i] == s[i - 1]) {  // 连续的相同括号只需要删除一个就行
                continue;
            }
            if (lremove + rremove > s.size() - i) {  // 剩余的字符串无法满足删除要求
                return;
            }
            // 尝试删除一个左括号
            if (lremove > 0 && s[i] == '(') {
                backTrack(s.substr(0, i) + s.substr(i + 1), i, lremove - 1, rremove);
            }
            // 尝试删除一个右括号
            if (rremove > 0 && s[i] == ')') {
                backTrack(s.substr(0, i) + s.substr(i + 1), i, lremove, rremove - 1);
            }
        }
    }

    // 判断一个字符串括号是否合法
    inline bool isValid(const string & str) {
        int cnt = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                cnt++;
            } else if (str[i] == ')') {
                cnt--;
                if (cnt < 0) {
                    return false;
                }
            }
        }

        return cnt == 0;
    }
};
// @lc code=end

int main() {
    Solution so;
    auto res = so.removeInvalidParentheses("()())()");
    return 0;
}