#include <iostream>
using namespace std;

class Dequeue{
  public:
  int* arr;
  int size;
  int front;
  int rear;

  Dequeue(int size){
    arr=new int[size];
    this->size=size;
    front = -1;
    rear = -1;
  }

  void push_back(int val){
    if(rear == size -1){
      cout << "Overflow" << endl;
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
    if(front == 0){
      cout << "Overflow" << endl;
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
    if(front == -1 && rear == -1){
      cout << "Underflow" << endl;
    }
    else if(front == rear){
      arr[rear]=-1;
      front=rear=-1;
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
int main(){
  Dequeue q(10);
  q.push_back(10);
  q.print();
  q.push_back(20);
  q.print();
  q.push_back(30);
  q.print();
  q.push_back(40);
  q.print();
  q.push_back(50);
  q.print();
  q.push_back(60);
  q.print();
  q.push_back(70);
  q.print();
  q.push_back(80);
  q.print();
  q.push_back(90);
  q.print();
  q.push_back(100);
  q.print();
  q.pop_front();
  q.print();
  q.pop_front();
  q.print();
  q.pop_front();
  q.print();
  q.pop_front();
  q.print();
  q.push_front(10);
  q.print();
  q.push_front(10);
  q.print();
  q.push_front(10);
  q.print();
  q.push_front(10);
  q.print();
  q.pop_back();
  q.print();
  q.pop_back();
  q.print();
  q.pop_back();
  q.print();
  q.pop_back();
  q.print();
  q.pop_back();
  q.print();
  q.pop_back();
  q.print();
  q.pop_back();
  q.print();
  q.pop_back();
  q.print();
  q.pop_back();
  q.print();
  q.pop_back();
  q.print();
  q.pop_back();
  q.print();

}