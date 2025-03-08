/*
 * @lc app=leetcode.cn id=136 lang=cpp
 * @lcpr version=30204
 *
 * [136] 只出现一次的数字
 *
 * https://leetcode.cn/problems/single-number/description/
 *
 * algorithms
 * Easy (74.58%)
 * Likes:    3279
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 1.6M
 * Testcase Example:  '[2,2,1]'
 *
 * 给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 
 * 你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
 * 
 * 
 * 
 * 
 * 
 * 示例 1 ：
 * 
 * 
 * 输入：nums = [2,2,1]
 * 
 * 输出：1
 * 
 * 
 * 示例 2 ：
 * 
 * 
 * 输入：nums = [4,1,2,1,2]
 * 
 * 输出：4
 * 
 * 
 * 示例 3 ：
 * 
 * 
 * 输入：nums = [1]
 * 
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * -3 * 10^4 <= nums[i] <= 3 * 10^4
 * 除了某个元素只出现一次以外，其余每个元素均出现两次。
 * 
 * 
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


// 自己没想出来用异或运算，因为这个还涉及到异或运算的交换律
// 
// 既满足时间复杂度又满足空间复杂度，就要提到位运算中的异或运算 XOR，主要因为异或运算有以下几个特点：
// 一个数和 0 做 XOR 运算等于本身：a⊕0 = a
// 一个数和其本身做 XOR 运算等于 0：a⊕a = 0
// XOR 运算满足交换律和结合律：a⊕b⊕a = (a⊕a)⊕b = 0⊕b = b


class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int ans = 0 ;
            for(int i = 0; i < nums.size(); i++){
                ans = ans ^nums[i];
            }
            return ans;
        }
    };
// @lc code=end



/*
// @lcpr case=start
// [2,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [4,1,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */

