/*
 * @lc app=leetcode.cn id=225 lang=cpp
 * @lcpr version=30204
 *
 * [225] 用队列实现栈
 *
 * https://leetcode.cn/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (65.64%)
 * Likes:    931
 * Dislikes: 0
 * Total Accepted:    428.7K
 * Total Submissions: 652.9K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
 * 
 * 实现 MyStack 类：
 * 
 * 
 * void push(int x) 将元素 x 压入栈顶。
 * int pop() 移除并返回栈顶元素。
 * int top() 返回栈顶元素。
 * boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 你只能使用队列的标准操作 —— 也就是 push to back、peek/pop from front、size 和 is empty
 * 这些操作。
 * 你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：
 * ["MyStack", "push", "push", "top", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * 输出：
 * [null, null, null, 2, 2, false]
 * 
 * 解释：
 * MyStack myStack = new MyStack();
 * myStack.push(1);
 * myStack.push(2);
 * myStack.top(); // 返回 2
 * myStack.pop(); // 返回 2
 * myStack.empty(); // 返回 False
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= x <= 9
 * 最多调用100 次 push、pop、top 和 empty
 * 每次调用 pop 和 top 都保证栈不为空
 * 
 * 
 * 
 * 
 * 进阶：你能否仅用一个队列来实现栈。
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
class MyStack {
public:
    queue<int> que1;
    MyStack() {
        
    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int size = que1.size();
        size --;
        for(int i = 0; i < size; i++){
            int ele = que1.front();
            que1.pop();
            que1.push(ele);
        }
        int rtn = que1.front();
        que1.pop();
        return rtn;
    }
    
    int top() {
        int size = que1.size();
        size --;
        for(int i = 0; i < size; i++){
            int ele = que1.front();
            que1.pop();
            que1.push(ele);
        }
        int rtn = que1.front();
        que1.pop();
        que1.push(rtn);
        return rtn;
    }
    
    bool empty() {
        return que1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyStack", "push", "push", "top", "pop", "empty"][[], [1], [2], [], [], []]\n
// @lcpr case=end

 */

