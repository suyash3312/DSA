#include <iostream>
using namespace std;

class Node {
  public:
  int data;
  Node* next;

  Node() {
    this->next = NULL;
  }

  Node(int data1, Node* next1) {
    this->data = data1;
    this->next = next1;
  }
};

void insertAtTail(Node* &head, Node* &tail, int data) {
  Node* newNode = new Node(data, NULL);
  if(tail == NULL) {
    head = newNode;
    tail = newNode;
  }
  else {
    tail->next = newNode;
    tail = newNode;
  }
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL) {
      Node* temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }
    return prev;
}

void AddOnetoLL(Node* &head) {
  head = reverse(head);
  Node* temp = head;
  int carry = 1;

  while (temp != NULL) {
    int totalSum = temp->data + carry;
    temp->data = totalSum % 10;
    carry = totalSum / 10;
    if (carry == 0) {
      break;
    }
    if (temp->next == NULL && carry != 0) {
      temp->next = new Node(carry, NULL);
      carry = 0;
    }
    temp = temp->next;
  }
  
  head = reverse(head);
}

void print(Node* head) {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

int main() {
  Node* head = NULL;
  Node* tail = NULL;

  insertAtTail(head, tail, 9);
  insertAtTail(head, tail, 9);  
  insertAtTail(head, tail, 9);
  insertAtTail(head, tail, 9);
  cout << "Original list: ";
  print(head);  // Expected output: 1->2->NULL

  AddOnetoLL(head);

  cout << "List after adding 1: ";
  print(head);  // Expected output: 1->3->NULL

  return 0;
}
