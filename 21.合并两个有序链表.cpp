/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (63.03%)
 * Likes:    1131
 * Dislikes: 0
 * Total Accepted:    299.9K
 * Total Submissions: 475.6K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 *
 *
 *
 * 示例：
 *
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* head;
        ListNode* p;
        ListNode* q;
        if (l1->val <= l2->val) {
            head = l1;
            p = l1;
            q = l2;
        } else {
            head = l2;
            p = l2;
            q = l1;
        }

        ListNode* tmp;

        while (q != nullptr) {
            if (p->next == nullptr) {
                p->next = q;
                break;
            } else if (p->next->val >= q->val) {
                tmp = q->next;
                q->next = p->next;
                p->next = q;
                q = tmp;
                p = p->next;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};
// @lc code=end

