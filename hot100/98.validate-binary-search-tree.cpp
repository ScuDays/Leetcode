/*
 * @lc app=leetcode.cn id=98 lang=cpp
 * @lcpr version=30204
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode.cn/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (38.66%)
 * Likes:    2511
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.8M
 * Testcase Example:  '[2,1,3]'
 *
 * 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
 * 
 * 有效 二叉搜索树定义如下：
 * 
 * 
 * 节点的左子树只包含 小于 当前节点的数。
 * 节点的右子树只包含 大于 当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：root = [2,1,3]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 输入：root = [5,1,4,null,null,3,6]
 * 输出：false
 * 解释：根节点的值是 5 ，但是右子节点的值是 4 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目范围在[1, 10^4] 内
 * -2^31 <= Node.val <= 2^31 - 1
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

 // 解法：
 // 对于每一个节点有min和max，保证节点大于min，小于max
 // 每次对于左节点更新max并启动max，对于右节点更新min并启用min。
// class Solution {
//     public:
//         bool result = true;
//         bool isValidBST(TreeNode* root) {
//             if(root == nullptr)return true;
//             recure(root->left, 0, root->val, false, true);
//             recure(root->right, root->val, 0, true, false);
//             return result;
//         }
//         void recure(TreeNode* root, int min, int max, bool ifMin, bool ifMax){
//             if(root == nullptr)return;
//             if(ifMin == true && root->val <= min){
//                 result = false;
//                 return;
//             }
//             if(ifMax == true && root->val >= max){
//                 result = false;
//                 return;
//             }
    
//             recure(root->left, min, root->val, ifMin, true);
//             recure(root->right, root->val, max, true, ifMax);
//         }
//     };

// 第二次
class Solution {
public:
    // lower: 下层 表示当前节点必须比下层大
    // upper: 上层 表示当前节点必须比上层小
    bool __dfs(TreeNode* root, long long lower, long long upper) {
        if (!root)
            return true;

        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        // 在递归中修改条件，左节点必须比当前节点小，修改上层条件，同理右节点
        // 那为什么不用max 和 min 呢？因为本身已经保证了左节点比当前节点小，否则返回false了，
        // 所以不需要用min 或者 max。
        return __dfs(root->left, lower, root->val) &&
               __dfs(root->right, root->val, upper);
    }
    bool isValidBST(TreeNode* root) { 
        return __dfs(root, LONG_MIN, LONG_MAX); 
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,1,3]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,4,null,null,3,6]\n
// @lcpr case=end

 */

