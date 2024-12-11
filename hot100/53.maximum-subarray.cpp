/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30204
 *
 * [53] 最大子数组和
 *
 * https://leetcode.cn/problems/maximum-subarray/description/
 *
 * algorithms
 * Medium (55.75%)
 * Likes:    6847
 * Dislikes: 0
 * Total Accepted:    1.9M
 * Total Submissions: 3.4M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 *
 * 子数组 是数组中的一个连续部分。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
 * 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [1]
 * 输出：1
 *
 *
 * 示例 3：
 *
 * 输入：nums = [5,4,-1,7,8]
 * 输出：23
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 *
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
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
    int maxSubArray(vector<int> &nums)
    {
        // if(nums.size() == 1)return nums[0];
        // for (int i = 1; i < nums.size(); i++)
        // {
        //     nums[i] += nums[i - 1];
        // }
        // vector<int> Negative;
        // vector<int> Positive;

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     int themin = 0;
        //     int themax = 0;
        //     if (nums[i] < 0)
        //     {
        //         while ( i < nums.size() && nums[i] < 0 )
        //         {
        //             if (nums[i] < themin)
        //                 themin = nums[i];
        //             i++;
        //         }
        //         Negative.push_back(themin);
        //     }
        //     if (nums[i] >= 0)
        //     {
        //         while (i < nums.size() && nums[i] > 0  )
        //         {
        //             if (nums[i] > themax)
        //                 themax = nums[i];
        //             i++;
        //         }
        //         Positive.push_back(themax);
        //     }
        // }
        // for (auto a : Positive)
        // {
        //     printf("Positive %d ", a);
        // }
        // printf("\n");
        // for (auto a : Negative)
        // {
        //     printf("Negative %d ", a);
        // }
        //  printf("\n");
        //   printf("\n");
        // int themax = 0;
        // int size = max(Negative.size(), Positive.size());
        // for(int i = 0; i < size; i ++){
        //     int negt = 0;
        //     int post = 0;
        //     if(i < Negative.size())negt = Negative[i];
        //     if(i < Positive.size())post = Positive[i];
        //     int a = negt*(-1) + post ;
        //     themax = max(themax, a);
        // }
        // return themax;
        // 上面的思路有一点问题
        // 但是记住一个思路，前缀和可以把操作结合在计算前缀的路上。
        // int ret = INT_MIN;
        // int pre_min = 0;
        // int current = 0;

        // for(auto i: nums){
        //     current += i;
        //     ret = max(ret, current - pre_min);
        //     pre_min = min(pre_min, current);
        // }
        // return ret;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */
