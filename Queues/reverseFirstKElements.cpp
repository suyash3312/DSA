#include <iostream>
#include <queue>
using namespace std;


void reverseFirstKElements(queue<int>& q, int k){
  if(k==0){
    return;
  }
  int element = q.front();
  q.pop();
  reverseFirstKElements(q, --k);
  q.push(element);
}

void solve(queue<int>& q, int k){
  int n = q.size();
  int remainingElements=n-k;
  reverseFirstKElements(q, k);
  while(remainingElements != 0){
    int temp = q.front();
    q.pop();
    q.push(temp);
    --remainingElements;
  }
}
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
  q.push(90);
   q.push(100);
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
  q.push(90);
  q.push(100);
  
  solve(q, 3);
  
  cout << "\nAfter Reversing : ";
  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }
}