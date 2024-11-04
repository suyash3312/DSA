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

int length = 0;

void insertAtHead(Node* &head, Node* &tail, int data) {
  Node* newNode = new Node(data, NULL);
  if(head == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }
  length++;  // Update length after insertion
}

void insertAtTail(Node* &head, Node* &tail, int data) {
  Node* newNode = new Node(data, NULL);
  if(tail == NULL) {
    head = newNode;
    tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
  length++;  // Update length after insertion
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position) {
  if (position < 1 || position > length + 1) {
    cout << "Invalid position!" << endl;
    return;
  }

  if (position == 1) {
    insertAtHead(head, tail, data);
  } else if (position == length + 1) {
    insertAtTail(head, tail, data);
  } else {
    Node* newNode = new Node(data, NULL);
    Node* prev = NULL;
    Node* curr = head;

    for (int i = 1; i < position; i++) {
      prev = curr;
      curr = curr->next;
    }

    prev->next = newNode;
    newNode->next = curr;
    length++;  // Update length after insertion
  }
}

void print(Node* head) {
  Node* temp = head;
  while (temp != NULL) {
    cout << temp->data << "->";
    temp = temp->next;
  }
  
}

int main() {
  Node* head = NULL;
  Node* tail = NULL;

  insertAtHead(head, tail, 1000);
  insertAtTail(head, tail, 2000);
  insertAtPosition(head, tail, 1500, 2);
  insertAtPosition(head, tail, 3000, 4);  // Position 4 is valid now

  print(head);  // Expected output: 1000->1500->2000->3000->NULL
  cout << length << endl;
  return 0;
}
