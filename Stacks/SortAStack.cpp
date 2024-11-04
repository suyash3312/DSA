#include <iostream>
#include<stack>
using namespace std;

void insertElementInSortedStack(stack<int> &st, int &insertElement){
  if(st.empty()==true || insertElement > st.top()){
    st.push(insertElement);
    return;
  }
  int temp=st.top();
  st.pop();

  insertElementInSortedStack(st, insertElement);
  st.push(temp);
}
void sortStack(stack<int> &st){
  if(st.size()==0){
    return;
  }
  int temp=st.top();
  st.pop();
  
  sortStack(st);
  insertElementInSortedStack(st, temp);
}

int main() {
  stack<int>st; 
  st.push(15);
  st.push(22);
  st.push(39);
  st.push(14);
  st.push(75);
  st.push(61);
  while(!st.empty()){
    cout << st.top();
    st.pop();
  }cout <<endl;
  st.push(15);
  st.push(22);
  st.push(39);
  st.push(14);
  st.push(75);
  st.push(61);
  sortStack(st);
  while(!st.empty()){
    cout << st.top();
    st.pop();
  }
}