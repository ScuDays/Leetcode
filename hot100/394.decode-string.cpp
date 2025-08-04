/*
 * @lc app=leetcode.cn id=394 lang=cpp
 * @lcpr version=30204
 *
 * [394] 字符串解码
 *
 * https://leetcode.cn/problems/decode-string/description/
 *
 * algorithms
 * Medium (60.13%)
 * Likes:    2018
 * Dislikes: 0
 * Total Accepted:    479.5K
 * Total Submissions: 795.7K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * 给定一个经过编码的字符串，返回它解码后的字符串。
 * 
 * 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
 * 
 * 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
 * 
 * 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "3[a]2[bc]"
 * 输出："aaabcbc"
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "3[a2[c]]"
 * 输出："accaccacc"
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "2[abc]3[cd]ef"
 * 输出："abcabccdcdcdef"
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = "abc3[cd]xyz"
 * 输出："abccdcdcdxyz"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 30
 * s 由小写英文字母、数字和方括号 '[]' 组成
 * s 保证是一个 有效 的输入。
 * s 中所有整数的取值范围为 [1, 300] 
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

// 这道题关键在于str什么时候要被压栈清空，什么时候不被清空接着计算。
// 如果后面是 [ 说明他是下一级的运算，要将当前str压栈清空，如果后面接着是字母的话就会添加在str后面。
class Solution {
public:
    string decodeString(string s) {
        stack<int> stack_num;
        stack<string> stack_str;
        int size = s.size();
        int num = 0;
        string str = "";
        for(int i = 0; i < size;){

            if(s[i] >= '0' && s[i] <= '9')
            {
                while(s[i] >= '0' && s[i] <= '9'){
                    num = num * 10 + s[i] - '0';
                    i ++;
                }
                continue;
            }
            else if((s[i] >= 'a' && s[i] <= 'z')){
                while((s[i] >= 'a' && s[i] <= 'z')){
                    str += s[i];
                    i ++;
                }
                continue;
            }
            else if(s[i] == '[') //将‘[’前的数字压入nums栈内， 字母字符串压入strs栈内
            {
                stack_num.push(num);
                num = 0;
                stack_str.push(str); 
                str = "";
                i ++;
            }
            else{
                int times = stack_num.top();
                stack_num.pop();
                for(int j = 0; j < times; ++ j){
                    stack_str.top() += str;
                }
                str = stack_str.top(); //之后若还是字母，就会直接加到res之后，因为它们是同一级的运算
                                  //若是左括号，res会被压入strs栈，作为上一层的运算
                stack_str.pop();
                i ++;
            }

        }

        return str;
    }

};
// @lc code=end



/*
// @lcpr case=start
// "3[a]2[bc]"\n
// @lcpr case=end

// @lcpr case=start
// "3[a2[c]]"\n
// @lcpr case=end

// @lcpr case=start
// "2[abc]3[cd]ef"\n
// @lcpr case=end

// @lcpr case=start
// "abc3[cd]xyz"\n
// @lcpr case=end

 */

