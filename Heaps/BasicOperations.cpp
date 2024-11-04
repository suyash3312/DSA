#include <iostream>
using namespace std;

class Heap {
public:
  int *arr;
  int capacity;
  int size = 0;

  Heap(int capacity) {
    this->arr = new int[capacity];
    this->capacity = capacity;
    this->size = 0;
  }
  void insert(int val) {
    if (size == capacity) {
      cout << "Heap Overflow";
      return;
    }
    size++;
    int index = size;
    arr[index] = val;

    while (index > 1) {
      int parentIndex = index / 2;
      if (arr[parentIndex] < arr[index]) {
        swap(arr[parentIndex], arr[index]);
        index = parentIndex;
      } else {
        break;
      }
    }
  }
  void deletefromHeap() {
    arr[1] = arr[size];
    size--;
    int index = 1;
    while (index <= size) {
      int leftIndex = index * 2;
      int rightIndex = index * 2 + 1;
      int largestElementIndex = index;
      if (leftIndex <= size && arr[leftIndex] > arr[largestElementIndex]) {
        largestElementIndex = leftIndex;
      }
      if (rightIndex <= size && arr[rightIndex] > arr[largestElementIndex]) {
        largestElementIndex = rightIndex;
      }
      if (index == largestElementIndex) {
        break;
      } else {
        swap(arr[index], arr[largestElementIndex]);
        index = largestElementIndex;
      }
    }
  }

  void print() {
    for (int i = 1; i <= size; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};
  void heapify(int arr[], int n, int index) {
    int leftIndex = index * 2;
    int rightIndex = index * 2 + 1;
    int largestElementIndex = index;
    if (leftIndex <= n && arr[leftIndex] > arr[largestElementIndex]) {
      largestElementIndex = leftIndex;
    }
    if (rightIndex <= n && arr[rightIndex] > arr[largestElementIndex]) {
      largestElementIndex = rightIndex;
    }
    if (largestElementIndex != index) {
      swap(arr[index], arr[largestElementIndex]);
      index = largestElementIndex;
      heapify(arr, n, index);
    }
  }
  void buildHeap(int arr[], int n) {
    for (int index = n / 2; index > 0; index--) {
      heapify(arr, n, index);
    }
  }
  void heapSort(int arr[], int n){
    while(n != 1){
      swap(arr[1], arr[n]);
      n--;
      heapify(arr, n, 1);
    }
  }
int main() {
  int arr[] = {-1, 5, 10, 15, 20, 25, 12};
  int n = 6;
  buildHeap(arr, n);
  cout << "printing heap: " << endl;
  for (int i = 1; i <= 6; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  heapSort(arr, n);
  cout << "printing heap: " << endl;
  for (int i = 1; i <= 6; i++) {
    cout << arr[i] << " ";
  }

  // Heap h(10);
  // h.insert(50);
  // h.insert(45);
  // h.insert(48);
  // h.insert(64);
  // h.insert(98);
  // h.insert(34);
  // h.insert(21);
  // h.insert(25);
  // h.insert(55);
  // h.print();
  // h.deletefromHeap();
  // h.print();
  // h.deletefromHeap();
}