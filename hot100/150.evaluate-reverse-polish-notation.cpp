/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30204
 *
 * [150] 逆波兰表达式求值
 *
 * https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (55.60%)
 * Likes:    978
 * Dislikes: 0
 * Total Accepted:    440.1K
 * Total Submissions: 788.8K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * 给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。
 *
 * 请你计算该表达式。返回一个表示表达式值的整数。
 *
 * 注意：
 *
 *
 * 有效的算符为 '+'、'-'、'*' 和 '/' 。
 * 每个操作数（运算对象）都可以是一个整数或者另一个表达式。
 * 两个整数之间的除法总是 向零截断 。
 * 表达式中不含除零运算。
 * 输入是一个根据逆波兰表示法表示的算术表达式。
 * 答案及所有中间计算结果可以用 32 位 整数表示。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：tokens = ["2","1","+","3","*"]
 * 输出：9
 * 解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
 *
 *
 * 示例 2：
 *
 * 输入：tokens = ["4","13","5","/","+"]
 * 输出：6
 * 解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
 *
 *
 * 示例 3：
 *
 * 输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
 * 输出：22
 * 解释：该算式转化为常见的中缀算术表达式为：
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= tokens.length <= 10^4
 * tokens[i] 是一个算符（"+"、"-"、"*" 或 "/"），或是在范围 [-200, 200] 内的一个整数
 *
 *
 *
 *
 * 逆波兰表达式：
 *
 * 逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。
 *
 *
 * 平常使用的算式则是一种中缀表达式，如 ( 1 + 2 ) * ( 3 + 4 ) 。
 * 该算式的逆波兰表达式写法为 ( ( 1 2 + ) ( 3 4 + ) * ) 。
 *
 *
 * 逆波兰表达式主要有以下两个优点：
 *
 *
 * 去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
 * 适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中
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

/* 错误思路*/
/*
    1.两个栈，一个符号，一个数字栈，一个符号栈
    2.从后往前遍历，一个一个加入栈中
    3.数字栈中每有两个数字，就从符号栈弹出一个符号进行计算
    4.计算结果压入数字栈

*/

/* 正确思路*/
/*
    错误思路的问题：
    1.搞错了逆波兰表达式的实际计算方法。

    纠正：
    1.用栈操作运算：
    2.遇到数字则入栈；
    3.遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中

*/
class Solution
{
public:
    int calculate(int num1, int num2, char symbol)
    {
        printf("num1:%d num2:%d symbol:%c\n", num1, num2, symbol);
        switch (symbol)
        {
        case '+':
            return num1 + num2;
            break;
        case '-':
            return num1 - num2;
            break;
        case '*':
            return num1 * num2;
            break;
        case '/':
            return num1 / num2;
            break;
        default:
            printf("发生错误\n");
            break;
        }
        return 0;
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<char> symbol;
        stack<int> number;
        int count = 0;
        for (int i = 0; i < tokens.size(); i++)
        {
            // 符号
            if ((tokens[i].size() == 1) && (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/'))
            {

               int num2 = number.top();
               number.pop();
               int num1 = number.top();
               number.pop();
               int result = calculate(num1, num2, tokens[i][0]);
               number.push(result);
            }
            // 数字
            else
            {
                // 转数字函数，记一下
                int num1 = stoi(tokens[i]);
                number.push(num1);
            }
        }
        return number.top();
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */
