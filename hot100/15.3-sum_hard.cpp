/*
 * @lc app=leetcode.cn id=15 lang=cpp
 * @lcpr version=30204
 *
 * [15] 三数之和
 *
 * https://leetcode.cn/problems/3sum/description/
 *
 * algorithms
 * Medium (38.63%)
 * Likes:    7153
 * Dislikes: 0
 * Total Accepted:    2M
 * Total Submissions: 5.3M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j !=
 * k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
 *
 * 注意：答案中不可以包含重复的三元组。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 解释：
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
 * 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
 * 注意，输出的顺序和三元组的顺序并不重要。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [0,1,1]
 * 输出：[]
 * 解释：唯一可能的三元组和不为 0 。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [0,0,0]
 * 输出：[[0,0,0]]
 * 解释：唯一可能的三元组和为 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> rtvec;
        set<vector<int>> theset;

        sort(nums.begin(), nums.end());
        if ((nums[0] > 0 && nums[nums.size() - 1] > 0) || (nums[0] < 0 && nums[nums.size() - 1] < 0))
        {
            return vector<vector<int>>();
        }
        for (int left = 0; left < nums.size() - 2; left++)
        {
            int addup = nums[left];
           // printf("addup:%d\n", addup);
            if (addup > 0)
                break;
            int mid = left + 1;
            int right = nums.size() - 1;

            while (mid < right)
            {
                if ((nums[mid] + nums[right] + addup) == 0)
                {
                    theset.insert(vector<int>{nums[left], nums[mid], nums[right]});
                    // 用set防止加入相同的元素组
                    // 也可以使两边元素一直往中间走，直到他们各不等于当前元素即可。
                }                    
                if ((nums[mid] + nums[right] + addup) >= 0)
                    right--;
                if ((nums[mid] + nums[right] + addup) < 0)
                    mid++;
                // printf("mid:%d,right:%d\n",mid,right);
            }
        }
        for(auto ele: theset){
            rtvec.push_back(ele);
        }
        return rtvec;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [-1,0,1,2,-1,-4]\n
// @lcpr case=end

// @lcpr case=start
// [0,1,1]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,0]\n
// @lcpr case=end

 */
