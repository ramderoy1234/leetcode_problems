
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr  || head->next ==nullptr || k==0) return head;
        ListNode*temp=head;
        int lenght=0;
        while(temp!=nullptr){
          lenght++;
          temp=temp->next;
        }
        k=k%lenght;
        if(k==0) return head;
        ListNode*fast=head;
        ListNode*slow=head;
        for(int i=0;i<k;i++){
          fast=fast->next;
        }
        while(fast->next!=nullptr){
          fast=fast->next;
          slow=slow->next;
        }
        fast->next=head;
        head=slow->next;
        slow->next=nullptr;

        return head;
    }
};