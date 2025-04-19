
class Solution {
  ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }

  // merge two sorted lists
  ListNode* mergeSort(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;

    while (list1 && list2) {
      if (list1->val < list2->val) {
        temp->next = list1;
        list1 = list1->next;
      } else {
        temp->next = list2;
        list2 = list2->next;
      }
      temp = temp->next;
    }

    temp->next = list1 ? list1 : list2;
    return dummy->next;
  }

public:
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;

    // Find middle and split the list
    ListNode* middle = findMiddle(head);
    ListNode* right = middle->next;
    middle->next = nullptr;
    ListNode* left = head;

    // Recursive sort
    left = sortList(left);
    right = sortList(right);

    // Merge the sorted halves
    return mergeSort(left, right);
  }
};
