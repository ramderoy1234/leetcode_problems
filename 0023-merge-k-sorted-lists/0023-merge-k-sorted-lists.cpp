class Solution {
  struct Compare{
    bool operator()(ListNode*a,ListNode*b){
      return a->val > b->val; // smaller values come first
    }
  };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,Compare>pq;

        for(ListNode* it:lists){
          if(it!=nullptr){
            pq.push(it);
          }
        }
        ListNode*dummy=new ListNode(0);
        ListNode*temp=dummy;
        while(!pq.empty()){
          ListNode*node=pq.top();
          pq.pop();
          temp->next=node;
          temp=temp->next;

          if(node->next!=nullptr){
            pq.push(node->next);
          }
        }
        return dummy->next;
    }
};