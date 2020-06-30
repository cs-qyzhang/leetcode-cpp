/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (37.64%)
 * Likes:    4513
 * Dislikes: 0
 * Total Accepted:    458.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 *
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 *
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 *
 * 示例：
 *
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 *
 *
 */

using namespace std;

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* res = l1;
        while (l1) {
            if (l2 != nullptr) {
                l1->val = l1->val + l2->val + carry;
                carry = l1->val / 10;
                l1->val = l1->val % 10;
                if (l1->next == nullptr && (l2->next != nullptr || carry))
                    l1->next = new ListNode(0);
                l1 = l1->next;
                l2 = l2->next;
            } else {
                l1->val += carry;
                carry = l1->val / 10;
                l1->val = l1->val % 10;
                if (l1->next == nullptr && carry)
                    l1->next = new ListNode(0);
                l1 = l1->next;
            }
        }
        return res;
    }
};
// @lc code=end

