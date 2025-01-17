/*
 * @lc app=leetcode.cn id=541 lang=cpp
 * @lcpr version=30204
 *
 * [541] 反转字符串 II
 *
 * https://leetcode.cn/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (57.63%)
 * Likes:    626
 * Dislikes: 0
 * Total Accepted:    329.9K
 * Total Submissions: 571.9K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
 *
 *
 * 如果剩余字符少于 k 个，则将剩余字符全部反转。
 * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "abcdefg", k = 2
 * 输出："bacdfeg"
 *
 *
 * 示例 2：
 *
 * 输入：s = "abcd", k = 2
 * 输出："bacd"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^4
 * s 仅由小写英文组成
 * 1 <= k <= 10^4
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
    string reverseStr(string s, int k)
    {
        int size = s.size();
        for (int i = 0; i < size;)
        {
            int left = i;
            int right = 0;
            int finish = 0;
            if (size - i >= 2 * k)
            {
                //printf(">2k,i:%d\n", i);
                right = i + k - 1;
                i += 2 * k;
            }
            else if ((size - i) < 2 * k && (size - i) >= k)
            {
                right = i + k - 1;
                // printf(">=k,<2k,i:%d\n", i);
                finish = 1;
            }
            else if ((size - i) < 2 * k && (size - i) < k)
            {
                //printf("<2k,i:%d\n", i);
                right = size - 1;
                finish = 1;
            }
            while (left < right)
            {
                char change = s[left];
                s[left] = s[right];
                s[right] = change;
                left++;
                right--;
            }
            if (finish == 1)
            {
                break;
            }
        }
        return s;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abcdefg"\n2\n
// @lcpr case=end

// @lcpr case=start
// "abcd"\n2\n
// @lcpr case=end

 */
