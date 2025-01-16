/*
 * @lc app=leetcode.cn id=454 lang=cpp
 * @lcpr version=30204
 *
 * [454] 四数相加 II
 *
 * https://leetcode.cn/problems/4sum-ii/description/
 *
 * algorithms
 * Medium (64.93%)
 * Likes:    1062
 * Dislikes: 0
 * Total Accepted:    321.5K
 * Total Submissions: 494.6K
 * Testcase Example:  '[1,2]\n[-2,-1]\n[-1,2]\n[0,2]'
 *
 * 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l)
 * 能满足：
 *
 *
 * 0 <= i, j, k, l < n
 * nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
 * 输出：2
 * 解释：
 * 两个元组如下：
 * 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) +
 * (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) +
 * (-1) + 0 = 0
 *
 *
 * 示例 2：
 *
 * 输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == nums1.length
 * n == nums2.length
 * n == nums3.length
 * n == nums4.length
 * 1 <= n <= 200
 * -2^28 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2^28
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
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        int numsSize = nums1.size();
        for (int i = 0; i < numsSize; i++)
        {
            int numIn1 = nums1[i];
            int numIn3 = nums3[i];

            for (int j = 0; j < numsSize; j++)
            {
                int insertNum1 = numIn1 + nums2[j];
                int insertNum2 = numIn3 + nums4[j];
                if (map1.find(insertNum1) == map1.end())
                {
                    map1[insertNum1] = 1;
                }
                else
                {
                    map1[insertNum1]++;
                }
                if (map2.find(insertNum2) == map2.end())
                {
                    map2[insertNum2] = 1;
                }
                else
                {
                    map2[insertNum2]++;
                }
            }
        }
        /* debug */
        // for (const auto &elem : map1)
        // {
        //     printf("set1:first%d second %d\n", elem.first, elem.second);
        // }
        // for (const auto &elem : map2)
        // {
        //     printf("set2:first%d second %d\n", elem.first, elem.second);
        // }
        int rtn = 0;
        for (const auto &elem : map1)
        {
            int findNum = 0 - elem.first;
            if (map2.find(findNum) != map2.end())
            {
                rtn += map2[findNum] * elem.second;
            }
        }
        return rtn;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2]\n[-2,-1]\n[-1,2]\n[0,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n[0]\n[0]\n
// @lcpr case=end

 */
