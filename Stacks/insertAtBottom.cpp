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
int main() {
  stack<int>st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);
  st.push(6);
  int insertElement=500;
  insertElementAtBottom(st, insertElement);
  while(!st.empty()){
    cout << st.top();
    st.pop();
  }
}