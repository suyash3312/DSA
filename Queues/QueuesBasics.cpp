#include <iostream>
using namespace std;

class Queue{
  public:
  int* arr;
  int size;
  int front;
  int rear;

  Queue(int size){
    arr=new int[size];
    this->size=size;
    front=-1;
    rear=-1;
  }
  void push(int val){
    if(rear == size-1){
      cout << "Overflow" << endl;
    }
    else if(rear == -1 && front == -1){
      rear++;
      front++;
      arr[rear]=val;
    }
    else{
      rear++;
      arr[rear]=val;
    }
  }
  void pop(){
    if(front == -1 && rear == -1){
      cout << "Underflow" << endl;
    }
    else if(front == rear){
      arr[front] = -1;
      front=rear=-1;
    }
    else{
      arr[front] = -1;
      front++;
    }
  }
  int getSize(){
    if(rear == -1 && front == -1){
      return 0;
    }
    else{
      return rear - front + 1;
    }
  }
  void print(){
    for(int i=front; i<=rear; i++){
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  Queue q(5);
  q.push(4);
  q.push(5);
  q.push(6);
  q.push(7);
  q.push(8);
  cout << q.getSize() << endl;

  q.print();
  q.pop();
  q.print();
  q.pop();
  q.print();
  q.pop();
  q.print();
  q.pop();
  q.print();
  q.pop();
  q.print();
  q.pop();
  cout << q.getSize() << endl;
  q.print();
}