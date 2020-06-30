/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (58.35%)
 * Likes:    1123
 * Dislikes: 0
 * Total Accepted:    378K
 * Total Submissions: 647.8K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 *
 * 示例 1:
 *
 * 输入: 121
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 *
 *
 * 示例 3:
 *
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 *
 *
 * 进阶:
 *
 * 你能不将整数转为字符串来解决这个问题吗？
 *
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        int num = x;
        int rev = 0;
        while (num > 0) {
            if (rev > 214748364 || (rev == 214748364 && (num % 10) > 7))
                return false;
            if (rev < -214748364 || (rev == -214748364 && (num % 10) < -8))
                return false;
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev == x;
    }
};
// @lc code=end

