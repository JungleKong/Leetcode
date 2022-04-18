#include<vector>
#include<deque>
using namespace std;
/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    // 深度优先遍历
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

    // 广度优先遍历
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        int res = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    grid[i][j] = '0';
                    deque<pair<int, int>> q;
                    q.push_back({i, j});
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop_front();
                        if (x - 1 >= 0 && grid[x - 1][y] == '1') {
                            grid[x - 1][y] = '0';
                            q.push_back({x - 1, y});
                        }
                        if (x + 1 < rows && grid[x + 1][y] == '1') {
                            grid[x + 1][y] = '0';
                            q.push_back({x + 1, y});
                        }
                        if (y - 1 >= 0 && grid[x][y - 1] == '1') {
                            grid[x][y - 1] = '0';
                            q.push_back({x, y - 1});
                        }
                        if (y + 1 < cols && grid[x][y + 1] == '1') {
                            grid[x][y + 1] = '0';
                            q.push_back({x, y + 1});
                        }
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

