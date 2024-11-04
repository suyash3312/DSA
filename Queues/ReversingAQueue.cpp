#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void reverse(queue<int>& q){
  stack<int> st;
  while(!q.empty()){
    int temp = q.front();
    q.pop();
    st.push(temp);
  }
  while(!st.empty()){
    int temp = st.top();
    st.pop();
    q.push(temp);
  }
}

// void reverse(queue<int>& q){
//   if(q.empty()){
//     return;
//   }
//   int element = q.front();
//   q.pop();
//   reverse(q);
//   q.push(element);
// }

int main() {
  queue<int>q;
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  q.push(60);
  q.push(70);
  q.push(80);
  cout << "Before Reversing : ";
  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }
  q.push(10);
  q.push(20);
  q.push(30);
  q.push(40);
  q.push(50);
  q.push(60);
  q.push(70);
  q.push(80);
  reverse(q);
  cout << "\nAfter Reversing : ";
  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }
}