/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=30204
 *
 * [3] 无重复字符的最长子串
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
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() < 2)
            return s.size();
        int themax = 0;
        int right = 0;
        int left = 1;
        // int current = 1;
        while (left < s.size())
        {

            if (left == s.size() - 1)
            {   
                int a = 0;
                for (int i = right; i < left; i++)
                {
                    if (s[i] == s[left])
                    {
                        themax = max(themax, left - right);
                        a = 1;
                        // current = 1;
                    }
                }
                if(a == 0 ){
                    themax = max(themax, left - right + 1);
                }
               
            }
            for (int i = right; i < left; i++)
            {
                if (s[i] == s[left])
                {
                    themax = max(themax, left - right);
                    right = i + 1;
                    // current = 1;
                }
            }
            left++;
        }
        return themax;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */
