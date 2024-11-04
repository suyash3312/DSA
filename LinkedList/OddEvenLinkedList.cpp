class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Pointers for odd and even lists
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // To connect at the end

        // Iterate over the list
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next; // Connect odd nodes
            odd = odd->next;        // Move to next odd node
            even->next = odd->next; // Connect even nodes
            even = even->next;      // Move to next even node
        }

        // Connect the end of odd list to the head of the even list
        odd->next = evenHead;

        return head;
    }
};
