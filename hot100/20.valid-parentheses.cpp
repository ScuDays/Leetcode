/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30204
 *
 * [20] 有效的括号
 *
 * https://leetcode.cn/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (44.38%)
 * Likes:    4617
 * Dislikes: 0
 * Total Accepted:    2M
 * Total Submissions: 4.6M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 *
 * 有效字符串需满足：
 *
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "()"
 *
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "()[]{}"
 *
 * 输出：true
 *
 *
 * 示例 3：
 *
 *
 * 输入：s = "(]"
 *
 * 输出：false
 *
 *
 * 示例 4：
 *
 *
 * 输入：s = "([])"
 *
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 仅由括号 '()[]{}' 组成
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
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> sign;
        char topChar;
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '[':
                sign.push(s[i]);
                break;
            case '(':
                sign.push(s[i]);
                break;
            case '{':
                sign.push(s[i]);
                break;
            case ')':
                if (sign.size() == 0)
                    return false;
                topChar = sign.top();
                if (topChar == '(')
                {
                    sign.pop();
                }
                else
                {
                    return false;
                }
                break;
            case ']':
                if (sign.size() == 0)
                    return false;
                topChar = sign.top();
                if (topChar == '[')
                {
                    sign.pop();
                }
                else
                {
                    return false;
                }
                break;
            case '}':
                if (sign.size() == 0)
                    return false;
                topChar = sign.top();
                if (topChar == '{')
                {
                    sign.pop();
                }
                else
                {
                    return false;
                }
                break;
            default:
                break;
            }
        }
        if (sign.size() != 0)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

 */
