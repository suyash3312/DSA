class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Edge case: if either list is empty
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode* a = headA;
        ListNode* b = headB;

        // Traverse both lists, switching to the other list when the end is reached
        while (a != b) {
            // Move to the next node, or switch to the other list's head if at the end
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }

        // Either both are null (no intersection) or both are at the intersection node
        return a;
    }
};