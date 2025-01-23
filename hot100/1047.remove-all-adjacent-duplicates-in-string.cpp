/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 * @lcpr version=30204
 *
 * [1047] 删除字符串中的所有相邻重复项
 *
 * https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/
 *
 * algorithms
 * Easy (73.04%)
 * Likes:    671
 * Dislikes: 0
 * Total Accepted:    355.3K
 * Total Submissions: 485.7K
 * Testcase Example:  '"abbaca"'
 *
 * 给出由小写字母组成的字符串 s，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
 *
 * 在 s 上反复执行重复项删除操作，直到无法继续删除。
 *
 * 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
 *
 *
 *
 * 示例：
 *
 * 输入："abbaca"
 * 输出："ca"
 * 解释：
 * 例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串
 * "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s 仅由小写英文字母组成。
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

/* 我这种是坏的做法，其实只需要一直和栈顶比较就行了，不需要last和now。
 * 二刷的时候注意
*/
class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> charStack;
        char last;
        char now;
        charStack.push(s[0]);
        last = s[0];
        for (int i = 1; i < s.size(); i++)
        {
            now = s[i];
            if (now == last)
            {
                charStack.pop();
                if (charStack.size() == 0)
                {
                    if (i + 1 < s.size())
                    {
                        last = s[i + 1];
                        charStack.push(last);
                        i++;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    last = charStack.top();
                }
            }
            else
            {
                last = now;
                charStack.push(last);
            }
        }
        string rtn;
        for (int i = charStack.size() - 1; i >= 0; i--)
        {
            rtn.insert(0, 1, charStack.top());
            charStack.pop();
        }
        return rtn;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abbaca"\n
// @lcpr case=end

 */
