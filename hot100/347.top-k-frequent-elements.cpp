/*
 * @lc app=leetcode.cn id=347 lang=cpp
 * @lcpr version=30204
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode.cn/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (64.24%)
 * Likes:    1947
 * Dislikes: 0
 * Total Accepted:    653.2K
 * Total Submissions: 1M
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 *
 *
 *
 * 示例 1:
 *
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 *
 *
 * 示例 2:
 *
 * 输入: nums = [1], k = 1
 * 输出: [1]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * k 的取值范围是 [1, 数组中不相同的元素的个数]
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 *
 *
 *
 *
 * 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
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

/*我的思路：
    很简单，不多说了*/

/*更好的：
    用大小堆*/
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> themap;
        for (int i = 0; i < nums.size(); i++)
        {
            if (themap.find(nums[i]) == themap.end())
            {
                themap.insert(pair(nums[i], 1));
            }
            else
            {
                auto a = themap.find(nums[i]);
                a->second = a->second + 1;
            }
        }
        vector<pair<int, int>> vec;
        for (auto &a : themap)
        {
            vec.push_back(pair(a.first, a.second));
        }
        sort(vec.begin(), vec.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.second > b.second; });
        vector<int> rtn;

        for (int i = 0; i < vec.size(); i++)
        {
            printf("%d %d\n", vec[i].first, vec[i].second);
        }
        for (int i = 0; i < k; i++)
        {
            rtn.push_back(vec[i].first);
        }
        return rtn;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,1,2,2,3]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

 */
