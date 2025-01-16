/*
 * @lc app=leetcode.cn id=18 lang=cpp
 * @lcpr version=30204
 *
 * [18] 四数之和
 *
 * https://leetcode.cn/problems/4sum/description/
 *
 * algorithms
 * Medium (36.64%)
 * Likes:    2013
 * Dislikes: 0
 * Total Accepted:    657.5K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a],
 * nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 *
 *
 * 0 <= a, b, c, d < n
 * a、b、c 和 d 互不相同
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 *
 *
 * 你可以按 任意顺序 返回答案 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,2,2,2,2], target = 8
 * 输出：[[2,2,2,2]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
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
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> rtnVect;
        set<vector<int>> VectSet;
        if (nums.size() < 4)
            return rtnVect;
        //printf("111\n");
        sort(nums.begin(), nums.end());
        if ((target < 0 && nums[0] > 0) || (target >= 0 && nums[0] > target))
            return rtnVect;

        printf("22\n");

        for (int left = 0; left < nums.size() - 3; left++)
        {
            // int addup = 0;
            // addup += nums[left];
           
            for (int mid_left = left + 1; mid_left < nums.size() - 2; mid_left++)
            {
                int right = nums.size() - 1;
                int mid_right = mid_left + 1;
                
                while (mid_right < right)
                {
                   //printf("left:%d mid_left:%d mid_right:%d right:%d\n\n",left, mid_left, mid_right,right );
                    //int addup = nums[left] + nums[mid_left] + nums[mid_right] + nums[right];
                    if ((long)nums[left] + nums[mid_left] + nums[mid_right] + nums[right] == target)
                    {
                       // printf("插入\n");
                        // printf("此时left:%d mid_left:%d mid_right:%d right:%d\n\n\n",left, mid_left, mid_right,right );
                        VectSet.insert(vector<int>{nums[left], nums[mid_left], nums[mid_right], nums[right]});
                        mid_right ++;
                    }
                    else if ((long)nums[left] + nums[mid_left] + nums[mid_right] + nums[right] > target)
                    {
                        right--;
                    }
                    else
                    {
                        mid_right++;
                    }
                }
            }
        }
        for (auto elem : VectSet)
        {
            rtnVect.push_back(elem);
        }
        return rtnVect;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,0,-1,0,-2,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [2,2,2,2,2]\n8\n
// @lcpr case=end

 */
