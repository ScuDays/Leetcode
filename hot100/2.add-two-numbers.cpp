/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=30204
 *
 * [2] 两数相加
 *
 * https://leetcode.cn/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (44.59%)
 * Likes:    10906
 * Dislikes: 0
 * Total Accepted:    2.2M
 * Total Submissions: 5M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 * 
 * 
 * 示例 2：
 * 
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 示例 3：
 * 
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 <= Node.val <= 9
 * 题目数据保证列表表示的数字不含前导零
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

 // 这道题卡了半天，题目有一个问题，然后又两个别的问题。
 // 题目问题：1：记得把进位 over 给清了
 // 别的问题：1：如果用malloc分配内存，一定要初始化所有数据，或者用memset清空数据。
 //          2：力扣里面如果用C++ 就要用 new ，因为他对应地使用delete 释放内存。
 //             如果选C 就要用 malloc 和 free。
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        struct ListNode* rtn_List = new ListNode(0);
        struct ListNode* rtn = rtn_List;

        int over = 0;
        while (1) {
            if (l1 == nullptr)
                break;
            if (l2 == nullptr)
                break;
            int value = l1->val + l2->val + over;
            over = 0;
            if(value >= 10){
                over = 1;
                value = value - 10; 
            }
            struct ListNode* tmp = new ListNode(0);
            tmp->val = value;
            rtn_List->next = tmp;
            rtn_List = rtn_List->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        struct ListNode* l3;
        if(l1 == nullptr){
            l3 = l2;
        }
        else{
            l3 = l1;
        }
        while(1){
            if (l3 == nullptr)
                break;
            int value = l3->val + over;
            over = 0;
            if(value >= 10){
                over = 1;
                value = value - 10; 
            }
            struct ListNode* tmp = new ListNode(0);
            tmp->val = value;
            rtn_List->next = tmp;
            rtn_List = rtn_List->next;
            l3 = l3->next;
        }
        if(over == 1){
            struct ListNode* tmp = new ListNode(0);
            tmp->val = 1;
            rtn_List->next = tmp;
            rtn_List = rtn_List->next;
        }
        return rtn->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */

