/*
 * @lc app=leetcode.cn id=101 lang=cpp
 * @lcpr version=30204
 *
 * [101] 对称二叉树
 *
 * https://leetcode.cn/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (61.41%)
 * Likes:    2888
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 2M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [1, 1000] 内
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * 
 * 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
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
    

// 我的思路，把左右两棵树，分别对称递归填到数组里，然后比较数组。
class Solution {
public:

    bool isSymmetric(TreeNode* root) {
        vector<int> vec1;
        vector<int> vec2;
        addAll1(root->left, &vec1);
        addAll2(root->right, &vec2);
        if(vec1.size() != vec2.size()){
            return false;
        }
        for(int i = 0; i < vec1.size(); i++){
            printf("%d %d\n",vec1[i], vec2[i]);
        }
        for(int i = 0; i < vec1.size(); i++){
            if(vec1[i] != vec2[i])return false;
        }

        return true;
    }
    void addAll1(TreeNode *root, vector<int> *vec){
        if(root == nullptr){
            (*vec).push_back(-1);
            return;
        }  
        (*vec).push_back(root->val);
        addAll1(root->left, vec);

        addAll1(root->right, vec);

        return;
    }
    void addAll2(TreeNode *root, vector<int> *vec){
        if(root == nullptr){
            (*vec).push_back(-1);
            return;
        }  
        (*vec).push_back(root->val);
        addAll2(root->right, vec);

        addAll2(root->left, vec);

        return;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,2,3,4,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,2,null,3,null,3]\n
// @lcpr case=end

 */

