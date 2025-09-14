/*
 * @lc app=leetcode.cn id=108 lang=cpp
 * @lcpr version=30204
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (79.56%)
 * Likes:    1613
 * Dislikes: 0
 * Total Accepted:    591.8K
 * Total Submissions: 740.7K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [-10,-3,0,5,9]
 * 输出：[0,-3,9,-10,null,5]
 * 解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [1,3]
 * 输出：[3,1]
 * 解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 按 严格递增 顺序排列
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

 // 二分递归
 // 出现问题，传指针的时候，我们要修改指针的值，所以要传指针的指针，前面忘了这个事情了。
// class Solution {
//     public:
//         TreeNode* sortedArrayToBST(vector<int>& nums) {
//             TreeNode* root = nullptr;
//             recure(&root, nums, 0, nums.size() - 1);
//             return root;
//         }
//         void recure(TreeNode** root, vector<int> &nums, int left, int right){
//             if(left > right)return;
//             int mid = (right - left) / 2 + left;
//             *root = new TreeNode(nums[mid]);
//             recure(&((*root)->left), nums, left, mid - 1);
//             recure(&((*root)->right), nums, mid + 1, right);
//         }
//     };

// 第二次写
// 使用 left > right 对应左闭右闭
class Solution {
public:
    TreeNode* __sortedArrayToBST(vector<int>& nums, int left, int right){
        if(left > right)return nullptr;
        int mid = left + (right - left) / 2;
        return new TreeNode(nums[mid], __sortedArrayToBST(nums, left, mid - 1), __sortedArrayToBST(nums, mid + 1, right));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return __sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-10,-3,0,5,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3]\n
// @lcpr case=end

 */

