/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hash_map;
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); ++i) {
            if (hash_map.find(s[i]) != hash_map.end()) {
                if (hash_map[s[i]] != t[i]) return false;
            } else {
                hash_map[s[i]] = t[i];
            }
        }
        // s 和 t 一一映射之后还要满足t 与 s 一一映射
        hash_map.clear();
        for (int i = 0; i < s.size(); ++i) {
            if (hash_map.find(t[i]) != hash_map.end()) {
                if (hash_map[t[i]] != s[i]) return false;
            } else {
                hash_map[t[i]] = s[i];
            }
        }
        return true;
    }
};
// @lc code=end

int main() {
    Solution so;
    so.isIsomorphic("badc", "baba");
    return 0;
}