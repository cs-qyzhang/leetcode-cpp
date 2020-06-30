/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (41.85%)
 * Likes:    1643
 * Dislikes: 0
 * Total Accepted:    311K
 * Total Submissions: 742.7K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 *
 * 有效字符串需满足：
 *
 *
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 *
 *
 * 注意空字符串可被认为是有效字符串。
 *
 * 示例 1:
 *
 * 输入: "()"
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入: "()[]{}"
 * 输出: true
 *
 *
 * 示例 3:
 *
 * 输入: "(]"
 * 输出: false
 *
 *
 * 示例 4:
 *
 * 输入: "([)]"
 * 输出: false
 *
 *
 * 示例 5:
 *
 * 输入: "{[]}"
 * 输出: true
 *
 */

using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if (s == "")
            return true;

        auto isLeft = [&](char c) {
            return c == '(' || c == '[' || c == '{';
        };

        auto isRight = [&](char c) {
            return c == ')' || c == ']' || c == '}';
        };

        auto isPair = [&](char left, char right) {
            return (left == '(' && right == ')') ||
                   (left == '[' && right == ']') ||
                   (left == '{' && right == '}');
        };

        stack<char> stk;
        for (auto& c : s) {
            if (isLeft(c))
                stk.push(c);
            else if (stk.empty())
                return false;
            else {
                if (isPair(stk.top(), c))
                    stk.pop();
                else
                    return false;
            }
        }
        return stk.empty();
    }
};
// @lc code=end

