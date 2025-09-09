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
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)return 0;
        unordered_set<char> set;
        int current = 0;
        int max = 1;

        for(int right = 0,left = 0; right < s.size(); right ++){
            if(set.count(s[right] == 0)){
                set.insert(s[right]);
                current ++;
                max = std::max(current, max);
            }
            else{
                while(set.count(s[right]) != 0){
                    set.erase(s[left]);
                    left ++;
                    current --;
                }
                set.insert(s[right]);
                current ++;
                max = std::max(current, max);
            } 
        }
        return max;
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
