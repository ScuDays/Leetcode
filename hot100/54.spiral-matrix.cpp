/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=30204
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (53.73%)
 * Likes:    1952
 * Dislikes: 0
 * Total Accepted:    774.1K
 * Total Submissions: 1.4M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int heng = matrix[0].size();
        int shu = matrix.size();
        printf("heng:%d, shu:%d \n", heng, shu);
        vector<int> rtn;
        int loc_heng = -1;
        int loc_shu = 0;
        while (1) {
            // 向右
            for (int i = 0; i < heng; i++) {
                loc_heng++;
                rtn.push_back(matrix[loc_shu][loc_heng]);
                printf("%d ", matrix[loc_shu][loc_heng]);
            }
            printf("\n此时坐标x:%d  y:%d\n", loc_heng, loc_shu);
            shu--;
            if (shu == 0)
                break;

            // 向下
            for (int i = 0; i < shu; i++) {
                loc_shu++;
                rtn.push_back(matrix[loc_shu][loc_heng]);
                printf("%d ", matrix[loc_shu][loc_heng]);
            }
            printf("\n此时坐标x:%d  y:%d\n", loc_heng, loc_shu);
            heng--;
            if (heng == 0)
                break;

            // 向左
            for (int i = 0; i < heng; i++) {
                loc_heng--;
                rtn.push_back(matrix[loc_shu][loc_heng]);
                printf("%d ", matrix[loc_shu][loc_heng]);
            }
            printf("\n此时坐标x:%d  y:%d\n", loc_heng, loc_shu);
            shu--;
            if (shu == 0)
                break;
            
            // 向上
            for (int i = 0; i < shu; i++) {
                loc_shu--;
                rtn.push_back(matrix[loc_shu][loc_heng]);
                printf("%d ", matrix[loc_shu][loc_heng]);
            }
            printf("\n此时坐标x:%d  y:%d\n", loc_heng, loc_shu);
            heng--;
            if (heng == 0)
                break;
                
        }
        return rtn;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */

