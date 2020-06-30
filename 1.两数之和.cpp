/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_multiset<int> nums_set(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int left = target - nums[i];
            int count = nums_set.count(left);
            if ((left != nums[i] && count > 0) || count > 1) {
                res.push_back(i);
                for (int j = i + 1; j < nums.size(); ++j) {
                    if (nums[j] == left) {
                        res.push_back(j);
                        return res;
                    }
                }
                res.pop_back();
            }
        }
        return res;
    }
};
// @lc code=end

