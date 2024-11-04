class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        ListNode* dummy = new ListNode(0); // Dummy node to handle edge cases
        dummy->next = head;
        ListNode* prev = dummy; // Previous pointer
        ListNode* current = head; // Current pointer
        
        while (current != nullptr) {
            // Detect duplicates
            bool isDuplicate = false;
            while (current->next != nullptr && current->val == current->next->val) {
                isDuplicate = true;
                current = current->next; // Skip all duplicates
            }
            
            if (isDuplicate) {
                // Skip all duplicates by connecting prev to the next of current
                prev->next = current->next;
            } else {
                // Move prev pointer if no duplicate was detected
                prev = prev->next;
            }
            
            // Move to the next node
            current = current->next;
        }
        
        return dummy->next;
    }
};