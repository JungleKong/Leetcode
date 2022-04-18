/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */
#include <cmath>
#include <vector>
// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        // 超时
        // int res = 0;
        // for (int i = 2; i < n; ++i) {
        //     if (isPrimes(i))
        //         ++res;
        // }
        // return res;

        std::vector<int> isPrime(n, 1);  // 存储每一个数
        int res = 0;
        for (int i = 2; i < n; ++i){
            if (isPrime[i]) {
                res += 1;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return res;
    }

    bool isPrimes(int n) {
        int nSqrt = std::pow(n, 0.5);
        for (int i = 2; i <= nSqrt; ++i) {
            if (n % i == 0) 
                return false;
        }
        return true;
    }
};
// @lc code=end

int main() {
    Solution so;
    so.countPrimes(10);
    return 0;
}
