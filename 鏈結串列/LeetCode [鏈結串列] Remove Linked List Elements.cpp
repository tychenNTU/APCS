/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *s_head, *now = head, *prev;
        s_head = new ListNode();
        s_head->next = head;
        prev = s_head;
        while(now){
            if(now->val == val){
                prev->next = now->next;
                ListNode *to_Delete = now;
                now = now->next;
                delete(to_Delete);
            }
            else{
                now = now->next;
                prev = prev->next;
            }
        }
        return s_head->next;
    }
};