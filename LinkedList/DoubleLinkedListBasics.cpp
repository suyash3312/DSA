#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* prev;
  Node* next;

  Node(int data1){
    this->data=data1;
    this->prev=NULL;
    this->next=NULL;
  }
};
int length=0;
  void insertAtHead(Node* &head, Node* &tail, int data){
    if(head==NULL){
      Node* newNode=new Node(data);
      head=newNode;
      tail=newNode;
      length++;
    }
    else{
      Node* newNode=new Node(data);
      newNode->next=head;
      head->prev=newNode;
      head=newNode;
      length++;
    }
  }
  void insertAtTail(Node* &head, Node* &tail, int data){
    if(tail==NULL){
      Node* newNode=new Node(data);
      head=newNode;
      tail=newNode;
      length++;
    }
    else{
      Node* newNode=new Node(data);
      newNode->prev=tail;
      tail->next=newNode;
      tail=newNode;
      length++;
    }
  }
  void insertAtPosition(Node*&head, Node* &tail, int data, int position){
    if(position<1 || position>length+1){
      cout << "INVALID POSITION";
      return;
    }
    else if(position==1){
      insertAtHead(head, tail, data);
    }
    else if(position==length+1){
      insertAtTail(head, tail, data);
    }
    else{
      Node* newNode=new Node(data);
      Node* currentNode=head;
      Node* previousNode=NULL;
      while(position!=1){
        position--;
        currentNode=currentNode->next;
        previousNode=currentNode->prev;
      }
      previousNode->next=newNode;
      currentNode->prev=newNode;
      newNode->next=currentNode;
      newNode->prev=previousNode;
      length++;
    }
  }
  void print(Node* &head){
    Node* temp=head;
    cout << "NULL";
    while(temp!=NULL){
      cout<< "<-" ;
      cout << temp->data << "->";
      temp=temp->next;
    }
    cout << "NULL" << endl;
    cout << length;
  }
  int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtPosition(head, tail, 100, 3);
    print(head);
}