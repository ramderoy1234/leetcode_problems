
class Solution {
    ListNode*reverseNode(ListNode*head){
        ListNode*prev=nullptr;
        ListNode*curr=head;
        ListNode*nextptr=nullptr;
        while(curr!=nullptr){
            nextptr=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextptr;
        }
        return prev;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || n<=0){
            return head;
        }
        ListNode*prev=nullptr;
        ListNode*reverse=reverseNode(head);
        ListNode*temp=reverse;
        for(int i=1;i<n;i++){
            prev=temp;
            temp=temp->next;
        }
        if(prev!=nullptr){
            prev->next=temp->next;
        }
        else{
            reverse=temp->next;
        }
        return reverseNode(reverse);
    }
};