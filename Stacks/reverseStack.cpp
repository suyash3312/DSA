#include <iostream>
#include<stack>
using namespace std;
void insertElementAtBottom(stack<int> &st, int &insertElement){
  if(st.size()==0){
    st.push(insertElement);
    return;
  }
  int temp=st.top();
  st.pop();

  insertElementAtBottom(st, insertElement);
  st.push(temp);
}
void reverseStack(stack<int> &st){
  if(st.size() == 0){
    return;
  }
  int temp=st.top();
  st.pop();

  reverseStack(st);
  insertElementAtBottom(st, temp);
}
int main() {
  stack<int>st; 
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);
  st.push(6);
  while(!st.empty()){
    cout << st.top();
    st.pop();
  }cout <<endl;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);
  st.push(6);
  reverseStack(st);
  while(!st.empty()){
    cout << st.top();
    st.pop();
  }
}