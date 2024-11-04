//BETTER SOLUTION WITH LESS SPACE COMPLEXITY O(1)

// class Solution {
// public:
//     ListNode* swapNodes(ListNode* head, int k) {
//         if (!head || !head->next) {
//             return head;
//         }
        
//         ListNode* first = head;
//         ListNode* second = head;
//         ListNode* current = head;
        
//         // Move `first` to the k-th node
//         for (int i = 1; i < k; ++i) {
//             if (current) {
//                 current = current->next;
//             }
//         }
//         first = current;
        
//         // Move `current` to the end, and `second` to the k-th node from the end
//         while (current->next) {
//             current = current->next;
//             second = second->next;
//         }
        
//         // Swap values of `first` and `second`
//         if (first != second) {
//             int temp = first->val;
//             first->val = second->val;
//             second->val = temp;
//         }
        
//         return head;
//     }
// };

// MY SOLUTION

class Solution {
public:
    int getLength(ListNode* &head) {
        ListNode* temp = head;
        int length = 0;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        int len = getLength(head);
        ListNode* temp = head;
        int* arr = new int[len];
        
        // Store values in the array
        for (int i = 0; i < len; i++) {
            arr[i] = temp->val;
            temp = temp->next;
        }

        // Swap the k-th element from start and k-th from end
        if (k <= len) {
            int t = arr[k - 1];
            arr[k - 1] = arr[len - k];
            arr[len - k] = t;
        }

        // Update the linked list with new values
        temp = head;
        for (int i = 0; i < len; i++) {
            temp->val = arr[i];
            temp = temp->next;
        }

        // Deallocate memory
        delete[] arr;

        return head;
    }
};
