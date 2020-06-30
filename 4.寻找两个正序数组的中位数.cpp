/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (38.31%)
 * Likes:    2813
 * Dislikes: 0
 * Total Accepted:    215.1K
 * Total Submissions: 561.3K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
 *
 * 请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 *
 * 你可以假设 nums1 和 nums2 不会同时为空。
 *
 *
 *
 * 示例 1:
 *
 * nums1 = [1, 3]
 * nums2 = [2]
 *
 * 则中位数是 2.0
 *
 *
 * 示例 2:
 *
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 *
 * 则中位数是 (2 + 3)/2 = 2.5
 *
 *
 */

using namespace std;

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        int p = 0;
        int q = 0;
        for (int i = 0; i < (size + 1) / 2 - 1; ++i) {
            if (q == nums2.size())
                p++;
            else if (p == nums1.size())
                q++;
            else if (nums1[p] < nums2[q])
                p++;
            else
                q++;
        }
        if (p == nums1.size()) {
            return (size & 1) ? (nums2[q]) : (double(nums2[q] + nums2[q + 1]) / 2.0);
        } else if (q == nums2.size()) {
            return (size & 1) ? (nums1[p]) : (double(nums1[p] + nums1[p + 1]) / 2.0);
        } else {
            if (size & 1)
                return (nums1[p] < nums2[q]) ? nums1[p] : nums2[q];
            else {
                if (nums1[p] < nums2[q]) {
                    if (p + 1 < nums1.size() && nums1[p + 1] < nums2[q])
                        return (nums1[p] + nums1[p + 1]) / 2.0;
                }
                if (nums2[q] < nums1[p]) {
                    if (q + 1 < nums2.size() && nums2[q + 1] < nums1[p])
                        return (nums2[q] + nums2[q + 1]) / 2.0;
                }
                return (nums1[p] + nums2[q]) / 2.0;
            }
        }
    }
};
// @lc code=end

