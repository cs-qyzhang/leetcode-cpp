/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (52.05%)
 * Likes:    758
 * Dislikes: 0
 * Total Accepted:    136.1K
 * Total Submissions: 261.3K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 *
 * 示例:
 *
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
 *
 */

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode head(0);
        head.next = nullptr;
        vector<ListNode*> sort_list;
        sort_list.reserve(lists.size());

        for (auto list : lists) {
            if (list)
                sort_list.push_back(list);
        }
        sort(sort_list.begin(), sort_list.end(), [&](ListNode* a, ListNode* b) {
            return a->val > b->val;
        });

        ListNode* pos = &head;
        while (!sort_list.empty()) {
            pos->next = sort_list.back();
            pos = pos->next;
            sort_list.pop_back();
            if (pos->next != nullptr) {
                sort_list.push_back(pos->next);
                for (int i = sort_list.size() - 2; i >= 0; --i) {
                    if (sort_list[i]->val < sort_list[i + 1]->val)
                        swap(sort_list[i], sort_list[i + 1]);
                    else
                        break;
                }
            }
        }
        return head.next;
    }
};
// @lc code=end

ListNode* makeList(vector<int> nums) {
    if (nums.empty())
        return nullptr;
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    for (auto x : nums) {
        p->next = new ListNode(x);
        p = p->next;
    }
    p->next = nullptr;
    return head->next;
}

int main(void) {
    Solution s;
    vector<ListNode*> input;
    input.push_back(makeList({1, 4, 5}));
    input.push_back(makeList({1, 3, 4}));
    input.push_back(makeList({2, 6}));
    ListNode* res = s.mergeKLists(input);
    cout << "answer:" << endl;
    while (res) {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}
