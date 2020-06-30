/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (75.63%)
 * Likes:    1132
 * Dislikes: 0
 * Total Accepted:    141.9K
 * Total Submissions: 187.7K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 *
 *
 *
 * 示例：
 *
 * 输入：n = 3
 * 输出：[
 * ⁠      "((()))",
 * ⁠      "(()())",
 * ⁠      "(())()",
 * ⁠      "()(())",
 * ⁠      "()()()"
 * ⁠    ]
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    inline void add(vector<string>& a, vector<string>& b) {
        int orgin_size = a.size();
        for (int i = 0; i < orgin_size; ++i) {
            for (int j = 1; j < b.size(); ++j) {
                a.push_back(a[i] + b[j]);
            }
            a[i].append(b[0]);
        }
    }

    inline void add(string a, vector<string>& b) {
        for (auto& s : b)
            s = a + s;
    }

    inline void add(vector<string>& a, string b) {
        for (auto& s : a)
            s.append(b);
    }

public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return vector<string>{};
        if (n == 1) return vector<string>{"()"};
        vector<vector<string>> table = {{""},{"()"}};
        table.reserve(n + 1);
        /*
         * 该层次的括号在最左边开始，根据括号在哪个地方结束进行分类：
         *   假设当前总括号对数为 n
         *   - 括号可以立马结束；
         *   - 可以在后面 1 对括号后结束，后面再加上 n - 2 对括号；
         *   - 可以在后面 2 对括号后结束，后面再加上 n - 3 对括号；
         *   - ......
         *
         * 代码中 j 为在几对括号后结束
         */
        for (int i = 2; i <= n; ++i) {
            table.push_back(vector<string>{});
            for (int j = i - 1; j >= 0; --j) {
                vector<string> tmp = table[j];
                add("(", tmp);
                add(tmp, ")");
                if (j != i - 1)
                    add(tmp, table[i - 1 - j]);
                table[i].insert(table[i].end(), tmp.begin(), tmp.end());
            }
        }
        return table[n];
    }
};
// @lc code=end

int main(void) {
    Solution s;
    auto res = s.generateParenthesis(3);
    for (auto& str : res)
        cout << str << endl;
    return 0;
}
