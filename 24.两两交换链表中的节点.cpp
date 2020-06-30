/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (65.94%)
 * Likes:    535
 * Dislikes: 0
 * Total Accepted:    118.2K
 * Total Submissions: 179.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 *
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 *
 *
 *
 * 示例:
 *
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 *
 *
 */

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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy_head;
        dummy_head.next = head;
        ListNode* p = &dummy_head;
        while (p->next && p->next->next) {
            ListNode* tmp = p->next->next->next;
            p->next->next->next = p->next;
            p->next = p->next->next;
            p->next->next->next = tmp;
            p = p->next->next;
        }
        return dummy_head.next;
    }
};
// @lc code=end

