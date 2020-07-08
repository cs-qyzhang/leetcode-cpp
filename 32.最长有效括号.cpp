/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (30.91%)
 * Likes:    723
 * Dislikes: 0
 * Total Accepted:    66.1K
 * Total Submissions: 213.1K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 *
 * 示例 1:
 *
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 *
 *
 * 示例 2:
 *
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 *
 *
 */

using namespace std;

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int i = 0;
        int j = 0;
        int max_len = 0;
        int level = 0;
        while (i < s.size() && j < s.size()) {
            if (s[j] == '(') {
                level++;
            } else {
                level--;
                if (level == 0) {
                    max_len = max(max_len, j - i + 1);
                } else if (level < 0) {
                    i = j + 1;
                    level = 0;
                }
            }
            j++;
        }

        i = s.size() - 1;
        j = s.size() - 1;
        level = 0;
        while (i >= 0 && j >= 0) {
            if (s[j] == ')') {
                level++;
            } else {
                level--;
                if (level == 0) {
                    max_len = max(max_len, i - j + 1);
                } else if (level < 0) {
                    i = j - 1;
                    level = 0;
                }
            }
            j--;
        }
        return max_len;
    }
};
// @lc code=end

