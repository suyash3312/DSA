#include <iostream>
using namespace std;

class CDequeue{
  public:
  int* arr;
  int size;
  int front;
  int rear;

  CDequeue(int size){
    arr=new int[size];
    this->size=size;
    front = -1;
    rear = -1;
  }

  void push_back(int val){
    if(rear == size -1 && front == 0 || rear == front - 1){
      cout << "Overflow" << endl;
    }
    else if(rear == size - 1 && front != 0){
      rear=0;
      arr[rear] = val;
    } 
    else if(rear == -1 && front == -1){
      rear++;
      front++;
      arr[rear] = val;
    }
    else{
      rear++;
      arr[rear] = val;
    }
  }

  void push_front(int val){
    if(front == 0 && rear == size - 1 || rear == front - 1){
      cout << "Overflow" << endl;
    }
    else if(rear != size - 1 && front == 0){
      front = size - 1;
      arr[front] = val;
    }
    else if(front == -1 && rear == -1){
      rear++;
      front++;
      arr[front]=val;
    }
    else{
      front--;
      arr[front]=val;
    }
  }

  void pop_back(){
    if(front == -1 && rear == -1 ){ // yeh line bhul jaoge
      cout << "Underflow" << endl;
    }
    else if(front == rear){
      arr[rear]=-1;
      front=rear=-1;
    }
    else if(rear == 0){
      rear = size -1;
    }
    else{
      arr[rear]=-1;
      rear--;
    }
  }

  void pop_front(){
    if(front == -1 && rear == -1){
      cout << "Underflow" << endl;
    }
    else if(front == size - 1){
      arr[front] = -1;
      front=0;
    }
    else if(front == rear){
      arr[front]=-1;
      front=rear=-1;
    }
    else{
      arr[front]=-1;
      front++;
    }
  }
  void print(){
    for(int i=0; i<size; i++){
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};