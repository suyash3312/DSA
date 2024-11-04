class Solution {
public:
    // Function to split the list into two halves
    ListNode* getMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;

        // Use two pointers: slow and fast
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to merge two sorted lists
    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == nullptr) return right;
        if (right == nullptr) return left;

        // Create a dummy node to start the merged list
        ListNode* dummy = new List Node(-1);
        ListNode* current = dummy;

        // Merge the two lists
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                current->next = left;
                left = left->next;
            } else{
                current->next = right;
                right = right->next;
            } 
            current = current->next;
        }

        // Append remaining nodes, if any
        if (left != nullptr) {
            current->next = left;
        } else {
            current->next = right;
        }

        ListNode* mergedHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return mergedHead;
    }

    // Function to perform merge sort on the linked list
    ListNode* sortList(ListNode* head) {
        // Base case: if the list is empty or has one element
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Split the list into two halves
        ListNode* middle = getMiddle(head);
        ListNode* nextOfMiddle = middle->next;
        middle->next = nullptr; // Break the list into two halves

        // Recursively sort each half
        ListNode* left = sortList(head);
        ListNode* right = sortList(nextOfMiddle);

        // Merge the two sorted halves
        return merge(left, right);
    }
};
