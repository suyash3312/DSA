#include <iostream>
#include <queue>
using namespace std;


void interleave(queue<int>& first){
  queue<int>second;
  int size=first.size()/2;
  for(int i=0; i<size; i++){
    int temp=first.front();
    first.pop();
    second.push(temp);
   }
  for(int i=0; i<size; i++){
    int temp=second.front();
    second.pop();
    first.push(temp);

    temp=first.front();
    first.pop();
    first.push(temp);
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
  cout << "Before Interleaving Operation : ";
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
  
  interleave(q);
  
  cout << "\nAfter Interleaving Operation : ";
  while(!q.empty()){
    cout << q.front() << " ";
    q.pop();
  }
}