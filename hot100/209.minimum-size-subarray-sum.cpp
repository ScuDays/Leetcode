// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 * @lcpr version=30204
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode.cn/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (46.83%)
 * Likes:    2317
 * Dislikes: 0
 * Total Accepted:    921K
 * Total Submissions: 2M
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 target 。
 * 
 * 找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr]
 * ，并返回其长度。如果不存在符合条件的子数组，返回 0 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：target = 7, nums = [2,3,1,2,4,3]
 * 输出：2
 * 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
 * 
 * 
 * 示例 2：
 * 
 * 输入：target = 4, nums = [1,4,4]
 * 输出：1
 * 
 * 
 * 示例 3：
 * 
 * 输入：target = 11, nums = [1,1,1,1,1,1,1,1]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 如果你已经实现 O(n) 时间复杂度的解法, 请尝试设计一个 O(n log(n)) 时间复杂度的解法。
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


// 反思：
// 不要总想着在遍历中就可以得到结果然后退出
// 很多时候就是要全部遍历得到结果
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        // int rtn = 1;
        // for( ;rtn <= target; rtn++){
        //     for(int begin = 0; begin + rtn - 1 < nums.size(); begin++){
        //         int sum = 0;
        //         for(int i = begin; i < begin + rtn; i++){
        //             sum += nums[i];
        //         }
        //         if(sum >= target){
        //             return rtn;
        //         }
        //     }
        // }
        // return 0;
        int min = -1;
        int right = 0;
        int left = 0;
        int sum  = 0;
        while(right < nums.size()){
            sum += nums[right];
            while(sum >= target){
                if((right - left + 1 < min) ||(min == -1)){
                    min = right - left + 1;
                }
                sum -= nums[left];
                left ++;
              
            }
            right ++;
        }
        if(min == -1){
            return 0;
        }
        return min;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 7\n[2,3,1,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[1,4,4]\n
// @lcpr case=end

// @lcpr case=start
// 11\n[1,1,1,1,1,1,1,1]\n
// @lcpr case=end

 */

