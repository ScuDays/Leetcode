/*
 * @lc app=leetcode.cn id=203 lang=cpp
 * @lcpr version=30204
 *
 * [203] 移除链表元素
 *
 * https://leetcode.cn/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (58.01%)
 * Likes:    1496
 * Dislikes: 0
 * Total Accepted:    830K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,6,3,4,5,6], val = 6
 * 输出：[1,2,3,4,5]
 *
 *
 * 示例 2：
 *
 * 输入：head = [], val = 1
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：head = [7,7,7,7], val = 7
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 列表中的节点数目在范围 [0, 10^4] 内
 * 1 <= Node.val <= 50
 * 0 <= val <= 50
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        // 哨兵节点，为了使用统一的方式遍历节点。
        ListNode *Sentinel = new ListNode(0, head);
        ListNode *last = Sentinel;
        while (head != nullptr)
        {
            if (head->val == val)
            {
                last->next = head->next;
                head = head->next;
            }
            else
            {
                last = last->next;
                head = head->next;
            }
        }
        return Sentinel->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,6,3,4,5,6]\n6\n
// @lcpr case=end

// @lcpr case=start
// []\n1\n
// @lcpr case=end

// @lcpr case=start
// [7,7,7,7]\n7\n
// @lcpr case=end

 */
