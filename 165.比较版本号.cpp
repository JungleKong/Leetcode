#include <string>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int start1 = 0, start2 = 0;
        while (true) {
            int a = version1.find('.', start1);
            int b = version2.find('.', start2);
            if (a == string::npos && b != string::npos) {
                int res = helper(version1.substr(start1, version1.size() - start1), version2.substr(start2, b - start2));
                if (res != 0) return res;
                else {
                    for (int i = b; i < version2.size(); ++i) {
                        if (version2[i] != '0' && version2[i] != '.')
                            return -1;
                    }
                    return 0;
                }
            }
            if (a != string::npos && b == string::npos) {
                int res = helper(version1.substr(start1, a - start1), version2.substr(start2, version2.size() - start2));
                if (res != 0) return res;
                else {
                    for (int i = a; i < version1.size(); ++i) {
                        if (version1[i] != '0' && version1[i] != '.')
                            return 1;
                    }
                    return 0;
                }
            }
            if (a == string::npos && b == string::npos) {
                return helper(version1.substr(start1, version1.size() - start1), version2.substr(start2, version2.size() - start2));
            }
            if (a != string::npos && b != string::npos) {
                int res = helper(version1.substr(start1, a - start1), version2.substr(start2, b - start2));
                if (res == 0) {
                    start1 = a + 1;
                    start2 = b + 1;
                    continue;
                } else return res;
            }
        }
        return 0;
    }

    // 这个比较大小的函数也可以不转换为整数,按位直接比较也行.
    int helper(string str1, string str2) {
        int a = atoi(str1.c_str());
        int b = atoi(str2.c_str());
        if (a < b) return -1;
        if (a > b) return 1;
        return 0;
    }

    int compareVersion2(string version1, string version2) {
        int n = version1.length(), m = version2.length();
        int i = 0, j = 0;
        while (i < n || j < m) {
            int x = 0;
            for (; i < n && version1[i] != '.'; ++i) {
                x = x * 10 + version1[i] - '0';
            }
            ++i; // 跳过点号
            int y = 0;
            for (; j < m && version2[j] != '.'; ++j) {
                y = y * 10 + version2[j] - '0';
            }
            ++j; // 跳过点号
            if (x != y) {
                return x > y ? 1 : -1;
            }
        }
        return 0;
    }
};

int main() {
    Solution so;
    cout << so.compareVersion("7.5.2.4", "7.5.3") << endl;
    return 0;
}
// @lc code=end

