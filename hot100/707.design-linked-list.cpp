// @lcpr-before-debug-begin

// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=707 lang=cpp
 * @lcpr version=30204
 *
 * [707] 设计链表
 *
 * https://leetcode.cn/problems/design-linked-list/description/
 *
 * algorithms
 * Medium (34.59%)
 * Likes:    1090
 * Dislikes: 0
 * Total Accepted:    360.1K
 * Total Submissions: 1M
 * Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n' +
  '[[],[1],[3],[1,2],[1],[1],[1]]'
 *
 * 你可以选择使用单链表或者双链表，设计并实现自己的链表。
 *
 * 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。
 *
 * 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。
 *
 * 实现 MyLinkedList 类：
 *
 *
 * MyLinkedList() 初始化 MyLinkedList 对象。
 * int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
 * void addAtHead(int val) 将一个值为 val
 * 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
 * void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
 * void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果
 * index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
 * void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
 *
 *
 *
 *
 * 示例：
 *
 * 输入
 * ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get",
 * "deleteAtIndex", "get"]
 * [[], [1], [3], [1, 2], [1], [1], [1]]
 * 输出
 * [null, null, null, null, 2, null, 3]
 *
 * 解释
 * MyLinkedList myLinkedList = new MyLinkedList();
 * myLinkedList.addAtHead(1);
 * myLinkedList.addAtTail(3);
 * myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
 * myLinkedList.get(1);              // 返回 2
 * myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
 * myLinkedList.get(1);              // 返回 3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= index, val <= 1000
 * 请不要使用内置的 LinkedList 库。
 * 调用 get、addAtHead、addAtTail、addAtIndex 和 deleteAtIndex 的次数不超过 2000 。
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
class MyLinkedList
{

public:
    struct LinkedNode
    {
        int val;
        LinkedNode *next;
        LinkedNode(int val) : val(val), next(nullptr) {}
    };

    MyLinkedList()
    {
        SentinelNode = new LinkedNode(0);
        size = 0;
    }

    int get(int index)
    {
        if (index > size - 1)
        {
            return -1;
        }
        LinkedNode *loopNode = SentinelNode;
        for (int i = 0; i <= index; i++)
        {
            loopNode = loopNode->next;
        }
        LinkedNode *loopNode1 = SentinelNode;

        for (int i = 0; i <= size; i++)
        {
            printf("值：%d\n", loopNode1->val);
            loopNode1 = loopNode1->next;
        }
        printf("分割\n");
        return loopNode->val;
    }

    void addAtHead(int val)
    {
        LinkedNode *newNode = new LinkedNode(val);
        if (SentinelNode->next != nullptr)
        {
            newNode->next = SentinelNode->next;
            SentinelNode->next = newNode;
        }
        else
        {
            SentinelNode->next = newNode;
        }
        size++;
    }

    void addAtTail(int val)
    {
        LinkedNode *loopNode = SentinelNode;
        for (int i = 0; i < size; i++)
        {
            loopNode = loopNode->next;
        }
        LinkedNode *newNode = new LinkedNode(val);
        loopNode->next = newNode;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
        {
            return;
        }
        LinkedNode *loopNode = SentinelNode;
        for (int i = 0; i < index; i++)
        {
            loopNode = loopNode->next;
        }
        LinkedNode *newNode = new LinkedNode(val);
        newNode->next = loopNode->next;
        loopNode->next = newNode;

        size++;
    }

    void deleteAtIndex(int index)
    {
        if(index > (size - 1)){
            return;
        }
        LinkedNode *loopNode = SentinelNode;
        for (int i = 0; i < index; i++)
        {
            if (loopNode == nullptr)
            {
                return;
            }
            loopNode = loopNode->next;
        }
        // 这里出了问题，搞了半天
        if (index != size - 1)
        {
            loopNode->next = loopNode->next->next;
        }
        else
        {
            loopNode->next = nullptr;
        }
        size --;
        // loopNode.
    }

private:
    LinkedNode *SentinelNode;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
