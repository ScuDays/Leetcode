/*
 * @lc app=leetcode.cn id=543 lang=cpp
 * @lcpr version=30204
 *
 * [543] 二叉树的直径
 *
 * https://leetcode.cn/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (61.64%)
 * Likes:    1664
 * Dislikes: 0
 * Total Accepted:    534.4K
 * Total Submissions: 861.7K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你一棵二叉树的根节点，返回该树的 直径 。
 * 
 * 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。
 * 
 * 两节点之间路径的 长度 由它们之间边数表示。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：root = [1,2,3,4,5]
 * 输出：3
 * 解释：3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。
 * 
 * 
 * 示例 2：
 * 
 * 输入：root = [1,2]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [1, 10^4] 内
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
//          TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//      };
    

// 解法：用的双递归暴力
class Solution {
public:
 
    int result = 0;
    int diameterOfBinaryTree(TreeNode *root){
        if(root == nullptr)return 0;
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        recure1(root);

        return result;
    }
    
    int recure1(TreeNode* root) {
        int left = 0;
        int right = 0;
        recure(root->left, 0, &left);
        recure(root->right, 0, &right);

        if(left + right > result){
            result = left + right;
        }
        return left + right;
    }

    void recure(TreeNode *root , int CurrentDepth, int *depth){
        if(root == nullptr){
            return;
        }else{
            CurrentDepth ++;
        }
        if(CurrentDepth > *depth){
            *depth = CurrentDepth;
        }
        recure(root->left, CurrentDepth, depth);
        recure(root->right, CurrentDepth, depth);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n
// @lcpr case=end

 */

