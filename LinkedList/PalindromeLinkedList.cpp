class Solution {
public:
    bool checkPalindrome(ListNode* head1, ListNode* head2) {
        while(head1!=NULL && head2!=NULL){
            if(head1->val != head2->val){
                return false;
            }
            else{
                head1=head1->next;
                head2=head2->next;
            }
        }
        return true;
    }
    void reverse(ListNode* &head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head=prev;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL) {
            fast = fast->next;
            if (fast->next != NULL) {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* mid = middleNode(head);
        ListNode* head1 = head;
        ListNode* head2 = mid->next;
        mid->next = NULL;
        reverse(head2);
        return checkPalindrome(head1, head2);
    }
};