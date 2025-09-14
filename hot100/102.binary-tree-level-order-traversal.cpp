/*
 * @lc app=leetcode.cn id=102 lang=cpp
 * @lcpr version=30204
 *
 * [102] 二叉树的层序遍历
 *
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (68.58%)
 * Likes:    2076
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 1.8M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
 *
 *
 *
 * 示例 1：
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[3],[9,20],[15,7]]
 *
 *
 * 示例 2：
 *
 * 输入：root = [1]
 * 输出：[[1]]
 *
 *
 * 示例 3：
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 2000] 内
 * -1000 <= Node.val <= 1000
 *
 *
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
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

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// 第一次
// class Solution
// {
// public:
//     vector<vector<int>> levelOrder(TreeNode *root)
//     {
//         queue<TreeNode *> que;
//         vector<vector<int>> result;
//         if (root != nullptr)
//         {
//             que.push(root);
//         }
//         int locat = 0;
//         while (!que.empty())
//         {
//             vector<int> vec;
//             int size = que.size();
//             for (int i = 0; i < size; i++)
//             {
//                 TreeNode *tre = que.front();
//                 que.pop();
//                 vec.push_back(tre->val);
//                 if (tre->left != nullptr)
//                 {
//                     que.push(tre->left);
//                 }
//                 if (tre->right != nullptr)
//                 {
//                     que.push(tre->right);
//                 }
//             }
//             result.push_back(vec);
//             locat++;
//         }
//         return result;
//     }
// };

// 第二次
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 注意这里
        if (!root)
            return vector<vector<int>>();
        queue<TreeNode*> que;
        que.push(root);
        int loop = 1;
        vector<vector<int>> ans_vec;
        while (que.size() != 0) {
            int next_loop = 0;
            vector<int> temp_vec;
            for (int i = 0; i < loop; i++) {
                TreeNode* temp_node = que.front();
                que.pop();
                temp_vec.push_back(temp_node->val);
                // 注意这里先left后right
                if (temp_node->left) {
                    que.push(temp_node->left);
                    next_loop++;
                }
                if (temp_node->right) {
                    que.push(temp_node->right);
                    next_loop++;
                }
            }
            loop = next_loop;
            ans_vec.push_back(temp_vec);
        }
        return ans_vec;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

 */
