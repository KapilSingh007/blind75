
    // Solution 1 :
    
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) {
            return false;
        }
        ListNode *ptr1 = head, *ptr2 = head->next;

        while (ptr2 && ptr2->next) {
            if (ptr1 == ptr2) {
                return true;
            }

            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }

        return false;
    }