/*
 * @lc app=leetcode.cn id=383 lang=cpp
 * @lcpr version=30204
 *
 * [383] 赎金信
 *
 * https://leetcode.cn/problems/ransom-note/description/
 *
 * algorithms
 * Easy (65.96%)
 * Likes:    942
 * Dislikes: 0
 * Total Accepted:    576.1K
 * Total Submissions: 870.9K
 * Testcase Example:  '"a"\n"b"'
 *
 * 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
 *
 * 如果可以，返回 true ；否则返回 false 。
 *
 * magazine 中的每个字符只能在 ransomNote 中使用一次。
 *
 *
 *
 * 示例 1：
 *
 * 输入：ransomNote = "a", magazine = "b"
 * 输出：false
 *
 *
 * 示例 2：
 *
 * 输入：ransomNote = "aa", magazine = "ab"
 * 输出：false
 *
 *
 * 示例 3：
 *
 * 输入：ransomNote = "aa", magazine = "aab"
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote 和 magazine 由小写英文字母组成
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
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> CharMap;
        for (int i = 0; i < magazine.size(); i++)
        {
            auto it = CharMap.find(magazine[i]);
            if(it == CharMap.end()){
                CharMap.insert(pair(magazine[i], 1));
            }
            else{
                it->second  ++;
            }
        }
        for (int i = 0; i < ransomNote.size(); i++)
        {
            auto it = CharMap.find(ransomNote[i]);
            if(it == CharMap.end()){
                return false;
            }
            else if(it->second == 1){
                CharMap.erase(it);
            }
            else{
                it->second --;
            }
        }
        return true;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "a"\n"b"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"ab"\n
// @lcpr case=end

// @lcpr case=start
// "aa"\n"aab"\n
// @lcpr case=end

 */
