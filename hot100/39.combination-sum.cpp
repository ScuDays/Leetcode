/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30204
 *
 * [39] 组合总和
 *
 * https://leetcode.cn/problems/combination-sum/description/
 *
 * algorithms
 * Medium (73.94%)
 * Likes:    3063
 * Dislikes: 0
 * Total Accepted:    1.3M
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target
 * 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
 * 
 * candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
 * 
 * 对于给定的输入，保证和为 target 的不同组合数少于 150 个。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：candidates = [2,3,6,7], target = 7
 * 输出：[[2,2,3],[7]]
 * 解释：
 * 2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
 * 7 也是一个候选， 7 = 7 。
 * 仅有这两种组合。
 * 
 * 示例 2：
 * 
 * 输入: candidates = [2,3,5], target = 8
 * 输出: [[2,2,2,2],[2,3,3],[3,5]]
 * 
 * 示例 3：
 * 
 * 输入: candidates = [2], target = 1
 * 输出: []
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= candidates.length <= 30
 * 2 <= candidates[i] <= 40
 * candidates 的所有元素 互不相同
 * 1 <= target <= 40
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
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    // 参数简化：我们不需要全局变量 sum，可以直接用 target 往下减
    // startIndex 用于控制搜索的起点，避免产生重复的组合（如 [2,3] 和 [3,2]）
    void dfs(vector<int>& candidates, int target, int startIndex) {
        // 基线条件 1：如果 target 小于 0，说明当前路径和已经超了，此路不通
        if (target < 0) {
            return;
        }
        // 基线条件 2：如果 target 等于 0，说明找到一个有效的组合
        if (target == 0) {
            res.push_back(path);
            return;
        }

        // for 循环是回溯算法的核心
        // 从 startIndex 开始遍历，确保我们不会使用到它之前的数字，从而避免重复组合
        for (int i = startIndex; i < candidates.size(); ++i) {
            // 1. 做出选择
            path.push_back(candidates[i]);
            
            // 2. 进入下一层决策
            // 因为数字可以重复使用，所以下一次递归的 startIndex 仍然是 i
            dfs(candidates, target - candidates[i], i);
            
            // 3. 撤销选择 (回溯)
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // 初始调用，从索引 0 开始
        dfs(candidates, target, 0);
        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

