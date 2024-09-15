
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
      ListNode*temp=head;
      while(temp!=nullptr &&temp->next!=nullptr ){
        int gcdVal= gcd(temp->val,temp->next->val);
        ListNode*gcdNode=new ListNode(gcdVal);

        // insert
        gcdNode->next=temp->next;
        temp->next=gcdNode;

        // move to next pointer
        temp=gcdNode->next;

      }
      return head;
    }
};