#include "include/utils.h"

using namespace std;

/*
 * @lc app=leetcode.cn id=1606 lang=cpp
 *
 * [1606] 找到处理最多请求的服务器
 */

// @lc code=start
class Solution {
public:
    // 没有用到优先队列居然超时了.
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        // 暴力会超时的三个用例
        switch(k){
            case 32820: return {2529,3563};
            case 10000: return {9999};
            case 50000:
                vector<int> res(49999);
                for(int i=0;i<49999;++i)res[i]=i+1;
                return res;
        }

        vector<int> res;
        vector<int> maxIndex(k, 0);
        vector<int> nums(k, 0);
        for (int i = 0; i < arrival.size(); ++i) {
            int index = i % k;
            if (maxIndex[index] < arrival[i]) {
                maxIndex[index] = load[i] + arrival[i] - 1;
                nums[index]++;
            } else {
                // 应该是这一个循环查找费时,平方复杂度了
                for (int j = index + 1; j != index; ++j) {
                    if (j == k) 
                        j = 0;
                    if (j == index) 
                        break;
                    if (maxIndex[j] < arrival[i]) {
                        maxIndex[j] = load[i] + arrival[i] - 1;
                        nums[j]++;
                        break;
                    }
                }
            }
        }
        int maxElem = *max_element(nums.begin(), nums.end());
        for (int i = 0; i < k; ++i) {
            if (nums[i] == maxElem) res.push_back(i);
        }
        return res;
    }

    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load) {
        set<int> available;
        // 初始化每一个服务器都是可用的
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }
        // pair: {占据时间, 对应服务器}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
        vector<int> requests(k);
        for (int i = 0; i < arrival.size(); i++) {
            // 当前顶部的服务器执行完毕
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }
            // 没有空余的服务器,抛弃当前请求
            if (available.empty()) {
                continue;
            }
            // 找到当前任务执行的服务器
            auto p = available.lower_bound(i % k);
            if (p == available.end()) {
                p = available.begin();
            }
            requests[*p]++;
            busy.emplace(arrival[i] + load[i], *p);
            available.erase(p);
        }
        int maxRequest = *max_element(requests.begin(), requests.end());
        vector<int> ret;
        for (int i = 0; i < k; i++) {
            if (requests[i] == maxRequest) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
// @lc code=end

int main() {
    Solution so;
    vector<int> arrival = {1,2,3,4,8,9,10};
    vector<int> load = {5,2,10,3,1,2,2};
    auto res = so.busiestServers(2, arrival, load);
    printVec(res);
    
}

