#include <iostream>
#include<stack>
using namespace std;

void findMiddleElement(stack<int> &st, int pos){
  if(pos==1){
    cout << "Deleting "<< st.top() << endl;
    st.pop() ;
    return;
  }
  pos--;
  int temp=st.top();
  st.pop();
  findMiddleElement(st, pos);
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
  int pos=0;
  cout<<st.size()<<endl;
  if(st.size() & 1){
  pos=(st.size()/2)+1;
  }else{
  pos=(st.size()/2);
  }
  findMiddleElement(st, pos);
  cout<<st.size()<<endl;
}