/*
 * @lc app=leetcode.cn id=104 lang=cpp
 * @lcpr version=30204
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (78.15%)
 * Likes:    1926
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 2M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树 root ，返回其最大深度。
 * 
 * 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 输入：root = [1,null,2]
 * 输出：2
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数量在 [0, 10^4] 区间内。
 * -100 <= Node.val <= 100
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

//   struct TreeNode {
//          int val;
//          TreeNode *left;
//          TreeNode *right;
//          TreeNode() : val(0), left(nullptr), right(nullptr) {}
//          TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//      };


     // 总结：
     // 可以使用层序遍历
     // 我这里直接还是用递归刀最底下

     class Solution {
        public:
            int depth;
            int maxDepth(TreeNode* root) {
                depth = 0;
                recure(root, depth);
                return depth;
            }
            void recure(TreeNode *root , int CurrentDepth){
                if(root == nullptr){
                    return;
                }else{
                    CurrentDepth ++;
                }
                if(CurrentDepth > depth){
                    depth = CurrentDepth;
                }
                recure(root->left, CurrentDepth);
                recure(root->right, CurrentDepth);
            }
        };
// @lc code=end



/*
// @lcpr case=start
// [3,9,20,null,null,15,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,null,2]\n
// @lcpr case=end

 */

