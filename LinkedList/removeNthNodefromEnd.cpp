class Solution {
public:
    int getLength(ListNode* &head){
        ListNode* temp=head;
        int length=0;
        while(temp!=NULL){
            temp=temp->next;
            length++;
        }
        return length;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=getLength(head);
        int position=0;
        ListNode* prev=NULL;
        ListNode* curr=head;
        if(head==NULL) return head;
        if(length==1 || (length-n)==0){
            ListNode* temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        // if((length-n)==0){
        //     ListNode* temp=head;
        //     head=head->next;
        //     delete temp;
        //     return head;
        // }
        while(position < (length-n)){
            prev=curr;
            curr=curr->next;
            position++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        return head;
    }
};