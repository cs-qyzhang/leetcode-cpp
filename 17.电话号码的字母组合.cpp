/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (53.78%)
 * Likes:    772
 * Dislikes: 0
 * Total Accepted:    125.7K
 * Total Submissions: 233.7K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 *
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 *
 *
 * 示例:
 *
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 *
 */

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<string>> table = {
            {"a","b","c"},
            {"d","e","f"},
            {"g","h","i"},
            {"j","k","l"},
            {"m","n","o"},
            {"p","q","r","s"},
            {"t","u","v"},
            {"w","x","y","z"}
        };

        auto combine = [&](vector<string>& res, int n) {
            res.reserve(res.size() * table[n].size());
            int size_before = res.size();
            for (int i = 1; i < table[n].size(); ++i)
                for (int j = 0; j < size_before; ++j)
                    res.push_back(res[j] + table[n][i]);
            for (int i = 0; i < size_before; ++i)
                res[i].append(table[n][0]);
        };

        if (digits == "")
            return vector<string>{};

        vector<string> res = {""};
        for (char& c : digits)
            combine(res, c - '2');
        return res;
    }
};
// @lc code=end

