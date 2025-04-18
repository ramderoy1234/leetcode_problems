
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL; 
        }
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*prev=nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev!=nullptr){
            prev->next=slow->next;
        }
        return head;
    }
};