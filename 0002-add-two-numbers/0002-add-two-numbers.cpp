
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp1=l1;
        ListNode*temp2=l2;
        int sum=0;
        int carry=0;
        ListNode*dummy=new ListNode(-1);
        ListNode*curr=dummy;
        while(temp1!=nullptr || temp2!=nullptr){
            sum=carry;
            if(temp1!=nullptr){
                sum+=temp1->val;
                temp1=temp1->next;
            }
            if(temp2!=nullptr){
                sum+=temp2->val;
                temp2=temp2->next;
            }
            carry=sum/10;
            ListNode*newNode=new ListNode(sum%10);
            curr->next=newNode;
            curr=newNode;
        }
        if(carry>0){
            ListNode*car=new ListNode(carry);
            curr->next=car;
        }
        return dummy->next;
    }
};