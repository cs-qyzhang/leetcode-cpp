/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (40.13%)
 * Likes:    663
 * Dislikes: 0
 * Total Accepted:    74.8K
 * Total Submissions: 185.9K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
 *
 *
 *
 * 示例 1:
 *
 * 输入: [1,2,0]
 * 输出: 3
 *
 *
 * 示例 2:
 *
 * 输入: [3,4,-1,1]
 * 输出: 2
 *
 *
 * 示例 3:
 *
 * 输入: [7,8,9,11,12]
 * 输出: 1
 *
 *
 *
 *
 * 提示：
 *
 * 你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。
 *
 */

using namespace std;

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        for_each(nums.begin(), nums.end(), [&](int& num) {
            if (num <= 0) {
                num = size + 1;
            }
        });
        for_each(nums.begin(), nums.end(), [&](int num) {
            if (abs(num) <= size)
                nums[abs(num) - 1] = nums[abs(num) - 1] < 0 ? nums[abs(num) - 1] : -nums[abs(num) - 1];
        });
        for (int i = 0; i < size; ++i) {
            if (nums[i] > 0)
                return i + 1;
        }
        return size + 1;
    }
};
// @lc code=end

