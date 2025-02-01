
class Solution {
    ListNode*reverseNode(ListNode*head){
        ListNode*prev=nullptr;
        ListNode*nextptr=nullptr;
        ListNode*curr=head;
        while(curr!=nullptr){
            nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*newHead=reverseNode(slow);
        ListNode*second=newHead;
        ListNode*first=head;
        while(first!=nullptr && second!=nullptr){
            if(first->val!=second->val){
                return false;
            }
            first=first->next;
            second=second->next;
        }
        return true;
    }
};