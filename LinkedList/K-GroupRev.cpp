//Example --- Input-  1>2>3>4>5>6
//                    k=2
//            Output- 2>1>4>3>6>5
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nextNode=curr->next;
        int len=getLength(head);

        if(len < k){
            return head;
        }
        int pos=0;
        while(pos < k){
            nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
            pos++;
        }
        ListNode* RecursiveAns=NULL;
        if(nextNode!=NULL){
            head->next=reverseKGroup(nextNode, k);
        }
        return prev;
    }
};