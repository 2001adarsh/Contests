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
    ListNode* insertionSortList(ListNode* head) {
        // 1 element will always be sorted.
        if (!head or !head->next)
            return head;

        //now curr to pe at 2nd position.
        // curr -> pointer forward.
        ListNode* curr = head->next, *prev = head, *temp;

        while (curr) {
            //remove this temp, and place it at appropriate position.
            temp = curr;
            prev->next = curr->next;
            curr = curr->next;

            //insert temp, at correct position before curr.
            ListNode* st = head; //pointer from head, to find appropriate position.
            if (head->val > temp->val) {
                //change head.
                temp->next = head;
                head = temp;
            }
            else {
                while (st->next != curr and st->next->val <= temp->val) {
                    st = st->next;
                }
                if (st->next == curr)
                    prev = temp;
                temp->next = st->next;
                st->next = temp;
            }
        }
        return head;
    }
};