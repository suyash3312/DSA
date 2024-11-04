#include <iostream>
using namespace std;

class CQueue{
  public:
  int* arr;
  int size;
  int front;
  int rear;

  CQueue(int size){
    arr=new int[size];
    this->size=size;
    front=-1;
    rear=-1;
  }
  void push(int val){
    if(front == 0 && rear == size-1 || rear == front -1){ // yeh line bhul jaoge
      cout << "Overflow" << endl;
    }
    else if(rear == size - 1 && front != 0){
      rear=0;
      arr[rear]=val;
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
    else if(front == size - 1){ // yeh bhul jaoge
      front = 0;
    }
    else{
      arr[front] = -1;
      front++;
    }
  }
  int getSize() {
    if (front == -1 && rear == -1) {
        return 0; // Queue is empty
    } 
    else if (rear >= front) {
        return rear - front + 1;
    } 
    else {
      return (size - front) + (rear + 1);
  }
}
  void print(){
    for(int i=0; i<size; i++){
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  CQueue q(5);
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  q.print();
  
  q.pop();
  q.print();
  q.pop();
  q.print();
  q.pop();
  q.print();
  q.pop();
  q.print();
  q.push(100);
  q.print();
  q.push(100);
  q.print();
  q.push(100);
  q.print();
  q.push(100);
  q.print();
  q.push(100);
  q.print();
  
}