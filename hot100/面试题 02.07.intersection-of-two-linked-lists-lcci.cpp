/*
 * @lc app=leetcode.cn id=面试题 02.07 lang=cpp
 * @lcpr version=30204
 *
 * [面试题 02.07] 链表相交
 *
 * https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/description/
 *
 * LCCI
 * Easy (66.91%)
 * Likes:    469
 * Dislikes: 0
 * Total Accepted:    276.8K
 * Total Submissions: 413.3K
 * Testcase Example:  '8\n[4,1,8,4,5]\n[5,0,1,8,4,5]\n2\n3'
 *
 * 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
 *
 * 图示两个链表在节点 c1 开始相交：
 *
 *
 *
 * 题目数据 保证 整个链式结构中不存在环。
 *
 * 注意，函数返回结果后，链表必须 保持其原始结构 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2,
 * skipB = 3
 * 输出：Intersected at '8'
 * 解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
 * 从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。
 * 在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB
 * = 1
 * 输出：Intersected at '2'
 * 解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。
 * 从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。
 * 在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
 * 输出：null
 * 解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。
 * 由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
 * 这两个链表不相交，因此返回 null 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * listA 中节点数目为 m
 * listB 中节点数目为 n
 * 0 <= m, n <= 3 * 10^4
 * 1 <= Node.val <= 10^5
 * 0 <= skipA <= m
 * 0 <= skipB <= n
 * 如果 listA 和 listB 没有交点，intersectVal 为 0
 * 如果 listA 和 listB 有交点，intersectVal == listA[skipA + 1] == listB[skipB +
 * 1]
 *
 *
 *
 *
 * 进阶：你能否设计一个时间复杂度 O(n) 、仅用 O(1) 内存的解决方案？
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int sizeA = 0;
        int sizeB = 0;
        ListNode *LoopA = headA;
        ListNode *LoopB = headB;
        while (LoopA != nullptr)
        {
            sizeA++;
            LoopA = LoopA->next;
        }
        while (LoopB != nullptr)
        {
            sizeB++;
            LoopB = LoopB->next;
        }
        int dif = 0;
        LoopA = headA;
        LoopB = headB;
        if (sizeA > sizeB)
        {
            dif = sizeA - sizeB;
            for (int i = 0; i < dif; i++)
            {
                LoopA = LoopA->next;
            }
        }
        else
        {
            dif = sizeB - sizeA;
            for (int i = 0; i < dif; i++)
            {
                LoopB = LoopB->next;
            }
        }
        while(LoopA != LoopB && LoopA != nullptr && LoopB != nullptr){
            LoopA = LoopA->next;
            LoopB = LoopB->next;
        }
        if(LoopA != nullptr && LoopB != nullptr && LoopA == LoopB){
            return LoopA;
        }
        return nullptr;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 8\n[4,1,8,4,5]\n[5,0,1,8,4,5]\n2\n3\n
// @lcpr case=end

// @lcpr case=start
// 2\n[0,9,1,2,4]\n[3,2,4]\n3\n1\n
// @lcpr case=end

// @lcpr case=start
// 0\n[2,6,4]\n[1,5]\n3\n2\n
// @lcpr case=end

 */
