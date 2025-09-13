/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30204
 *
 * [19] 删除链表的倒数第 N 个结点
 *
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (49.81%)
 * Likes:    3006
 * Dislikes: 0
 * Total Accepted:    1.6M
 * Total Submissions: 3.2M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 *
 *
 *
 * 示例 1：
 *
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 *
 *
 * 示例 2：
 *
 * 输入：head = [1], n = 1
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中结点的数目为 sz
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 *
 *
 *
 *
 * 进阶：你能尝试使用一趟扫描实现吗？
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
// class Solution
// {
// public:
//     ListNode *removeNthFromEnd(ListNode *head, int n)
//     {
//         vector<ListNode *> nodeList;
//         // 为什么需要有哨兵节点？
//         // 我们需要对第一个节点一视同仁，因为后面的每一个节点都有一个前节点可以操作。
//         // 所以我们虚拟出一个哨兵节点


//         //我的做法：
//         //用一个数组存遍历中的倒数n+1个节点，遍历到结尾就知道倒数第n个节点的前一个就行了

//         //好的做法：
//         //思路差不多，但是不用数组存的，直接用两个隔着固定距离的指针就可以了。
//         ListNode *Sentinel = new ListNode(0, head);
//         ListNode *loopNode = Sentinel;
//         while (loopNode != nullptr)
//         {
//             if (nodeList.size() != n + 1)
//             {
//                 nodeList.push_back(loopNode);
//             }
//             else
//             {
//                 nodeList.erase(nodeList.begin());
//                 nodeList.push_back(loopNode);
//             }
//             loopNode = loopNode->next;
//         }
//         ListNode *nodeBefore = nodeList[0];
//         ListNode *nodeDelete = nodeList[1];
//         if (nodeDelete->next == nullptr)
//         {
//             nodeBefore->next = nullptr;
//         }
//         else
//         {
//             nodeBefore->next = nodeBefore->next->next;
//         }
//         return Sentinel->next;
//     }
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* sentinel = new ListNode(0, head);
        ListNode* front = sentinel;
        ListNode* back = sentinel;
        for(int i = 0; i < n; i++)front = front->next;
        while(front->next){
            front = front->next;
            back = back->next;
        }
        back->next = back->next->next;
        return sentinel->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */
