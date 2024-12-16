class Solution {
    // Helper function to reverse a group of nodes
    ListNode* reverseNode(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* nextptr = nullptr;
        while (curr != nullptr) {
            nextptr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextptr;
        }
        return prev;
    }

public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        int length = 1;

        while (curr != nullptr) {
            ListNode* groupStart = curr;
            int count = 0;

            // Traverse nodes in the current group
            while (curr && count < length) {
                prev = curr;
                curr = curr->next;
                count++;
            }

            if (count % 2 == 0) {
                prev->next = nullptr; // Break the group connection
                ListNode* reversedGroup = reverseNode(groupStart);
                if (groupStart == head) {
                    head = reversedGroup;
                } else {
                    ListNode* temp = head;
                    while (temp->next != groupStart) {
                        temp = temp->next;
                    }
                    temp->next = reversedGroup;
                }
                // Move groupStart to the end of the reversed group
                groupStart->next = curr;
            }

            length++;
        }

        return head;
    }
};
