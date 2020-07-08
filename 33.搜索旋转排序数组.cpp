/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (38.14%)
 * Likes:    799
 * Dislikes: 0
 * Total Accepted:    136.7K
 * Total Submissions: 358.3K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 *
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 *
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 *
 * 你可以假设数组中不存在重复的元素。
 *
 * 你的算法时间复杂度必须是 O(log n) 级别。
 *
 * 示例 1:
 *
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 *
 *
 * 示例 2:
 *
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
private:
    int helper(vector<int>& nums, int left, int right, int target) {
        if (left == right)
            return (nums[left] == target) ? left : -1;
        if (nums[left] < nums[right]) {
            if (target >= nums[left] && target <= nums[right]) {
                while (left <= right) {
                    int middle = (left + right) / 2;
                    if (nums[middle] == target)
                        return middle;
                    else if (nums[middle] < target)
                        left = middle + 1;
                    else
                        right = middle - 1;
                }
            }
            return -1;
        } else {
            int middle = (left + right) / 2;
            if (nums[middle] == target)
                return middle;
            else if (nums[middle] <= nums[right]) {
                if (nums[middle] <= target && target <= nums[right])
                    return helper(nums, middle + 1, right, target);
                else
                    return helper(nums, left, middle - 1, target);
            } else {
                if (nums[left] <= target && target <= nums[middle])
                    return helper(nums, left, middle - 1, target);
                else
                    return helper(nums, middle + 1, right, target);
            }
        }
    }

public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        return helper(nums, 0, nums.size() - 1, target);
    }
};
// @lc code=end

int main(void) {
    Solution s;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    s.search(nums, 0);
    return 0;
}
