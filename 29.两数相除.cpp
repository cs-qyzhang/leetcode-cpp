/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 *
 * https://leetcode-cn.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (19.91%)
 * Likes:    363
 * Dislikes: 0
 * Total Accepted:    52.1K
 * Total Submissions: 261.2K
 * Testcase Example:  '10\n3'
 *
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 *
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 *
 * 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) =
 * -2
 *
 *
 *
 * 示例 1:
 *
 * 输入: dividend = 10, divisor = 3
 * 输出: 3
 * 解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
 *
 * 示例 2:
 *
 * 输入: dividend = 7, divisor = -3
 * 输出: -2
 * 解释: 7/-3 = truncate(-2.33333..) = -2
 *
 *
 *
 * 提示：
 *
 *
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
 *
 *
 */
#include <climits>
using namespace std;

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) return dividend;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (divisor == INT_MIN && dividend == INT_MIN) return 1;
        if (divisor == INT_MIN) return 0;

        bool negative = (dividend ^ divisor) < 0;
        int res = 0;
        if (dividend == INT_MIN) {
            dividend += negative ? divisor : -divisor;
            res += 1;
        }
        dividend = dividend < 0 ? -dividend : dividend;
        divisor = divisor < 0 ? -divisor : divisor;

        while (dividend >= divisor) {
            int cur_res = 1;
            int cur_divisor = divisor;
            while (cur_divisor < ((INT_MAX >> 1) + 1) && dividend >= cur_divisor) {
                cur_divisor = cur_divisor << 1;
                cur_res = cur_res << 1;
            }
            if (cur_divisor == divisor) {
                res += 1;
                dividend -= cur_divisor;
            } else {
                res += (cur_res >> 1);
                dividend -= (cur_divisor >> 1);
            }
        }
        return negative ? -res : res;
    }
};
// @lc code=end

int main(void) {
    Solution s;
    s.divide(-2147483648, -1109186033);
}
