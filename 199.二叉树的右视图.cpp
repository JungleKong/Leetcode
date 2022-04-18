#include "include/mytree.h"

/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // 广度优先遍历，每次遍历一层，把每层的最右边的节点放到结果集中
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (i == size - 1) res.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }

    // 深度优先遍历
    vector<int> rightSideView2(TreeNode* root) {
        vector<int> res;
        helper(root, 0, res);
        return res;
    }

    void helper(TreeNode* root, int depth, vector<int>& res) {
        if (!root) return;

        // 一定要先遍历右节点, 再遍历左节点. 如果是左试图则相反
        if (depth == res.size()) res.push_back(root->val);
        helper(root->right, depth + 1, res);
        helper(root->left, depth + 1, res);
    }
};
// @lc code=end

int main() {
    Solution so;
    vector<int> input = {1, 2, 3, null, 5, null, 4};
    TreeNode* root = CreatTree(input);
    PrintTree(root);
    vector<int> res = so.rightSideView(root);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}

