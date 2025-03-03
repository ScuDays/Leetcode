/*
 * @lc app=leetcode.cn id=236 lang=cpp
 * @lcpr version=30204
 *
 * [236] 二叉树的最近公共祖先
 *
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (72.48%)
 * Likes:    2909
 * Dislikes: 0
 * Total Accepted:    878.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出：3
 * 解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出：5
 * 解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 
 * 示例 3：
 * 
 * 输入：root = [1,2], p = 1, q = 2
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [2, 10^5] 内。
 * -10^9 <= Node.val <= 10^9
 * 所有 Node.val 互不相同 。
 * p != q
 * p 和 q 均存在于给定的二叉树中。
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //我的解法一坨屎，反正就是后序排列，回溯的解法。
 // 需要看一下题解看看怎么样解好。
class Solution {
    public:
        TreeNode* parent;
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            parent = nullptr;
            recure(root, p, q);
            return parent;
        }
        int recure(TreeNode* root, TreeNode* p, TreeNode* q) {
            if (root == nullptr)
                return (p->val + q->val) *2 ;
    
            int left = recure(root->left, p, q);
            int right = recure(root->right, p, q);
            if (root == p) {
                if (left == q->val || right == q->val) {
                    if (parent == nullptr) {
                        parent = root;
                    }
                }
            }
    
            if (root == q) {
                if (left == p->val || right == p->val) {
                    if (parent == nullptr) {
                        parent = root;
                    }
                }
            }
            if ((left == q->val && right == p->val) ||
                (left == p->val && right == q->val)) {
                if (parent == nullptr) {
                    parent = root;
                }
                if (root->val == p->val) {
                    return p->val;
                }
                if (root->val == p->val) {
                    return q->val;
                }
            }
            if (left == p->val || left == q->val) {
                return left;
            }
            if (right == p->val || right == q->val) {
                return right;
            }
            return root->val;
        }
    };
// @lc code=end



/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n1\n
// @lcpr case=end

// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n2\n
// @lcpr case=end

 */

