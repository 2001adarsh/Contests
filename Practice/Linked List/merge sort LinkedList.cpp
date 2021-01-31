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
    //merge two sorted list.
    ListNode* merge(ListNode* first, ListNode* second) {
        if (!first) return second;
        if (!second) return first;

        ListNode* root;
        if (first->val < second->val) {
            root = first;
            first = first->next;
        } else {
            root = second;
            second = second->next;
        }
        ListNode* head = root; // to not to loose the track of head.
        while (first and second) {
            if (first->val < second->val) {
                root->next = first;
                root = root->next;
                first = first->next;
            } else {
                root->next = second;
                root = root->next;
                second = second->next;
            }
        }
        if (!first) root->next = second;
        else root->next = first;
        return head;
    }

    ListNode* sorting(ListNode* head) {
        if (!head or !head->next)
            return head;

        //find mid.
        ListNode *slow = head, *fast = head, *prev = NULL;
        while (fast and fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //make separation btw two list.
        prev->next = NULL;

        ListNode* left = sorting(head);
        ListNode* right = sorting(slow);
        return merge(left, right);
    }

    //merge sort operated.
    ListNode* sortList(ListNode* head) {
        if (!head or !head->next)
            return head;
        ListNode* root = sorting(head);
        return root;
    }
};