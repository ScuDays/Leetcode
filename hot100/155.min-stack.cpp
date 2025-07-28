/*
 * @lc app=leetcode.cn id=155 lang=cpp
 * @lcpr version=30204
 *
 * [155] 最小栈
 *
 * https://leetcode.cn/problems/min-stack/description/
 *
 * algorithms
 * Medium (61.61%)
 * Likes:    1953
 * Dislikes: 0
 * Total Accepted:    774.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 实现 MinStack 类:
 * 
 * 
 * MinStack() 初始化堆栈对象。
 * void push(int val) 将元素val推入堆栈。
 * void pop() 删除堆栈顶部的元素。
 * int top() 获取堆栈顶部的元素。
 * int getMin() 获取堆栈中的最小元素。
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入：
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * 
 * 输出：
 * [null,null,null,null,-3,null,0,-2]
 * 
 * 解释：
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -2^31 <= val <= 2^31 - 1
 * pop、top 和 getMin 操作总是在 非空栈 上调用
 * push, pop, top, and getMin最多被调用 3 * 10^4 次
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

// 易错点
// 1：一开始想着直接维护一个最小值不就好了？发现如果pop出去的是最小值的话就会有问题，需要重新找出最小值
// 2：一开始需要往辅助数组里面push一个值。
class MinStack {
    std::stack<int> stack;
    // 辅助数组
    std::stack<int> stack_assist;
public:
    MinStack() {
        stack_assist.push(INT_MAX);
    }
    
    void push(int val) {
        int min = stack_assist.top();
        if(val < min){
            stack_assist.push(val);
        }
        else{
            stack_assist.push(min);
        }
        stack.push(val);
    }
    
    void pop() {
        stack.pop();
        stack_assist.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return stack_assist.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end



/*
// @lcpr case=start
// ["MinStack","push","push","push","getMin","pop","top","getMin"][[],[-2],[0],[-3],[],[],[],[]]\n
// @lcpr case=end

 */

