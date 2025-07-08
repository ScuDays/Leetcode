// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * @lcpr version=30204
 *
 * [56] 合并区间
 *
 * https://leetcode.cn/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (50.78%)
 * Likes:    2473
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 *
 *
 *
 * 示例 1：
 *
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 *
 *
 * 示例 2：
 *
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
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


// 这道题主要的问题就在于
// 循环中如果刚好最后一个区间也是可以和前面一个区间合并的话，
                    // if (intervals[j][1] >= max) {
                    //     max = intervals[j][1];
                    //     i = j;
                    // } else {
                    //     i = j;
                    // }
// 这里就必须要记得更新 i = j 
// 之前只通过 i = j - 1 来更新 i 的值
// 因为如果最后一个区间也被合并的话，就会出现下一次的值是i++ ，无论中间已经合并了多少个区间。
// 这样就可以避免重复添加最后一个区间的问题。
class Solution {
public:
    static bool compare1(vector<int> a, vector<int> b) { return a[0] < b[0]; }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    std:
        sort(intervals.begin(), intervals.end(), compare1);
        vector<vector<int>> rtn;
        for (int i = 0; i < intervals.size(); i++) {
            int min = intervals[i][0];
            int max = intervals[i][1];
            for (int j = i + 1; j < intervals.size(); j++) {
                if (intervals[j][0] > max) {
                    i = j - 1;
                    break;
                } else {
                    if (intervals[j][1] >= max) {
                        max = intervals[j][1];
                        i = j;
                    } else {
                        i = j;
                    }
                }
            }
            vector<int> tmp = {min, max};
            rtn.push_back(tmp);
        }
        return rtn;
    }
};

// 这个也是对的，这个更好
// class Solution {
// public:
//     static bool compare1(vector<int> a, vector<int> b) { return a[0] < b[0]; }
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//     std:
//         sort(intervals.begin(), intervals.end(), compare1);
//         vector<vector<int>> rtn;
//         for (int i = 0; i < intervals.size(); i++) {
//             int min = intervals[i][0];
//             int max = intervals[i][1];
//             for (int j = i + 1; j < intervals.size(); j++) {
//                 if (intervals[j][0] > max) {
//                     i = j - 1;
//                     break;
//                 } else {
//                     if (intervals[j][1] >= max) {
//                         max = intervals[j][1];
//                     } 
//                 }
//                 i = j;
//             }
//             vector<int> tmp = {min, max};
//             rtn.push_back(tmp);
//         }
//         return rtn;
//     }
// };
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[2,6],[8,10],[15,18]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,4],[4,5]]\n
// @lcpr case=end

 */
