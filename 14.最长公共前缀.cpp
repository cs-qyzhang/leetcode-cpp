/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (38.35%)
 * Likes:    1119
 * Dislikes: 0
 * Total Accepted:    297.7K
 * Total Submissions: 776.3K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 *
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 * 示例 1:
 *
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 *
 *
 * 示例 2:
 *
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 *
 *
 * 说明:
 *
 * 所有输入只包含小写字母 a-z 。
 *
 */

using namespace std;

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto commonPrefix = [&](string a, string b) {
            int min_len = a.size() < b.size() ? a.size() : b.size();
            for (int i = 0; i < min_len; ++i) {
                if (a[i] != b[i])
                    return a.substr(0, i);
            }
            return a.substr(0, min_len);
        };
        if (strs.empty()) return "";
        string res = strs[0];
        for (auto& s : strs) {
            res = commonPrefix(s, res);
        }
        return res;
    }
};
// @lc code=end

