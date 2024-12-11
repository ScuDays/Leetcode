/*
 * @lc app=leetcode.cn id=128 lang=cpp
 * @lcpr version=30204
 *
 * [128] 最长连续序列
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
    int longestConsecutive(vector<int> &nums)
    {
        // const int maxArr = (1000000000 * 2) + 1;
        // int arr[maxArr] = {0};
        // if(nums.size() == 0)return 0;
        // for(int i = 0; i < nums.size(); i++){
        //     arr[nums[i] + 1000000000] = 1;
        // }
        // int max  = 1;
        // for(int i = 1; i < maxArr ; i++){
        //     if(arr[i] == 0)break;
        //     arr[i] = (double)(arr[i] + arr[i - 1]);
        //     if(arr[i] > max)max  = arr[i];
        // }
        // printf("%d",max);
        // return max;

        unordered_set<int> hset;
        for (int i = 0; i < nums.size(); i++)
        {
            hset.insert(nums[i]);
        }
        int themax = 0;

        for (auto x : hset)
        {
            int current = 1;
            if (!hset.count(x - 1))
            {
                int y = x;
                while (hset.count(y + 1))
                {
                    y++;
                    current ++;
                }
                themax = max(themax, current);
            }
        }
        printf("%d",themax);
        return themax;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [100,4,200,1,3,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,3,7,2,5,8,4,6,0,1]\n
// @lcpr case=end

 */
