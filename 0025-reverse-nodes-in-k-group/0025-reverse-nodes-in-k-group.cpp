
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || k==1) return head;

        ListNode*check=head;
        for(int i=0;i<k;i++){
          if(check==nullptr) return head;
          check=check->next;
        }

        ListNode*curr=head;
        ListNode*prev=nullptr;
        ListNode*nextptr=nullptr;
        int cnt=0;
        while(curr!=nullptr && cnt<k){
          nextptr=curr->next;
          curr->next=prev;
          prev=curr;
          curr=nextptr;
          cnt++;
        }

        if(nextptr!=nullptr){
          head->next=reverseKGroup(nextptr,k);
        }
        return prev;
    }
};