/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int j = 0, ret = 0;
        string retStr;
        unordered_map<string, int> m, mbanned;
        string str;
        for (int i = 0; i < banned.size(); i++) mbanned[banned[i]]++;
        for (int i = 0; i <= paragraph.size(); i++) {
            if (isupper(paragraph[i])) paragraph[i] += 32;
            if (isalpha(paragraph[i])) {
                str += paragraph[i];
            }
            else if (str != "" && mbanned[str] != 1) {
                m[str]++;
                if (m[str] > ret) {
                    ret = m[str];
                    retStr = str;
                }
                // cout << str << endl;
                str.clear();
            }
            else {
                str.clear();
            }
        }
        return retStr;
    }
};
// @lc code=end

