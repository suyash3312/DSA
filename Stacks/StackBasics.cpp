#include <iostream>
using namespace std;

class Stack{
public:
  int* arr;
  int size;
  int top;
  
  Stack(int size){
    arr=new int[size];
    this->size=size;
    this->top=-1;
  }
  bool isEmpty(){
    if(top==-1){
      return true;
    }
    else{
      return false;
    }
  }
  void push(int data){
    if(top==size-1){
      cout << "Stack Overflow" << endl;
    }else{
      top++;
      arr[top]=data;
    }
  }
  void pop(){
    if(top==-1){
      cout << "Stack Underflow" << endl;
    }else{
      top--;
    }
  }
  void getTop(){
    if(top==-1){
      cout << "Stack Underflow" << endl;
    }else{
      cout << arr[top] << endl;
    }
  }
  int getSize(){
    return top+1;
  }
  void print(){
    for(int i=0; i < getSize(); i++){
      cout << "top : " << i << endl;
      cout << arr[i] << endl;
    }
    cout<<endl;
  }
};
int main() {
  Stack st(5);
  st.push(10);
  
  st.push(20);
  
  st.push(40);
  
  st.push(50);
  st.getTop();
  st.push(60);
  st.print();
  st.push(70);
  st.pop();
  st.pop();
  st.pop();
  st.pop();
  st.pop();
  st.print();
  st.pop();
  st.print();

}