
/*
 * @lc app=leetcode.cn id=48 lang=cpp
 * @lcpr version=30204
 *
 * [48] 旋转图像
 *
 * https://leetcode.cn/problems/rotate-image/description/
 *
 * algorithms
 * Medium (78.65%)
 * Likes:    2092
 * Dislikes: 0
 * Total Accepted:    792.7K
 * Total Submissions: 1M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
 * 
 * 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[7,4,1],[8,5,2],[9,6,3]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * 输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
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

// 这道题做了非常久
// 一共有三个错误
// 1：一开始弄坐标的时候弄混了，记得通过画图来做这个坐标
// 2：多移动了，如果是3 * 3 每行只用移动 2个，但是一开始每行移动3个，其实移动了12个，重复了3个，导致了错误。
// 3：偏移出问题了，一开始直接用i作为偏移，但是这个是有问题的，应该用i-begin作为偏移。
class Solution {
public: 

    static void print_all(vector<vector<int>>& matrix){
        int size = matrix.size();
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                printf("%d ",matrix[i][j]);
            }
            printf("\n");
        }
         printf("\n");
    }
    static void oneRotate(vector<vector<int>>& matrix, int number){
        int size = matrix.size();
        int begin = number;
        int finish = size - number - 1;
        
        for(int i = begin; i < finish; i++){
            int offset = i - begin;  // 计算偏移量
            
            // 保存左边位置的值
            int tmp = matrix[finish - offset][begin];  // 修正：finish - offset 而不是 finish - i
            
            // 四个位置的旋转：左←下←右←上←左
            matrix[finish - offset][begin] = matrix[finish][finish - offset];  // 下 -> 左
            matrix[finish][finish - offset] = matrix[i][finish];               // 右 -> 下
            matrix[i][finish] = matrix[begin][i];                             // 上 -> 右
            matrix[begin][i] = tmp;                                           // 左 -> 上
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < (matrix.size() / 2) ; i++){
            oneRotate(matrix, i);
        }                                                                           
        // oneRotate(matrix, 0);
    }
};

// 下面是错误版本
        // static void oneRotate(vector<vector<int>>& matrix, int number){
        //     int size = matrix.size();
        //     int begin = number;
        //     int finish = size - number - 1;
        //     int loop = finish - begin;
            
        //     for(int i = begin; i < finish ;i ++){
        //         // 左
        //         int tmp = matrix[finish - i][begin];
        //         // 下覆盖左
        //         matrix[finish - i][begin] = matrix[finish][finish - i];
        //         // 右覆盖下
        //         matrix[finish][finish - i] = matrix[i][finish];
        //         // 上覆盖右
        //         matrix[i][finish] = matrix[begin][i];
        //         // 上最后被覆盖
        //         matrix[begin][i] = tmp;
        //         // matrix[size - number - 1][i] = tmp;
        //     }
        // }

    
// @lc code=end



/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]\n
// @lcpr case=end

 */




 