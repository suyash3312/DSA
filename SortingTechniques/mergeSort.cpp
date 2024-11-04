#include <iostream>
using namespace std;

void merge(int arr[], int s, int e){
  int mid=(s+e)/2;
  int lenLeft=mid-s+1;
  int lenRight=e-(mid+1)+1;

  int* leftArray=new int[lenLeft];
  int* rightArray=new int[lenRight];

  int leftArrayIndex=0;
  int rightArrayIndex=0;
  //yahi pr galti hogi
  int mainArrayIndex=s;

  int k=s;
  for(int i=0; i<lenLeft; i++){
    leftArray[i]=arr[k];
    k++;
  }
  k=mid+1;
  for(int i=0; i<lenRight; i++){
    rightArray[i]=arr[k];
    k++;
  }

  while(leftArrayIndex < lenLeft && rightArrayIndex < lenRight){
    if(leftArray[leftArrayIndex] < rightArray[rightArrayIndex]){
      arr[mainArrayIndex]=leftArray[leftArrayIndex];
      leftArrayIndex++;
      mainArrayIndex++;
    }
    else{
      arr[mainArrayIndex]=rightArray[rightArrayIndex];
      rightArrayIndex++;
      mainArrayIndex++;
    }
  }
  while(leftArrayIndex < lenLeft){
    arr[mainArrayIndex]=leftArray[leftArrayIndex];
    leftArrayIndex++;
    mainArrayIndex++;
  }
  while(rightArrayIndex < lenRight){
    arr[mainArrayIndex]=rightArray[rightArrayIndex];
    rightArrayIndex++;
    mainArrayIndex++;
  }
  delete[] rightArray;
  delete[] leftArray;
}

void mergeSort(int arr[], int s, int e){
  if(s>=e){
    return;
  }
  int mid=(s+e)/2;
  mergeSort(arr, s, mid);
  mergeSort(arr, mid+1, e);
  merge(arr, s, e);
}

int main(){
  int arr[]={23,46,44,89,98,35,86,75};
  int length=8;
  int s=0, e=length-1;
  mergeSort(arr, s, e);

  for(int i=0; i<length;i++){
    cout << arr[i] << ",";
  }
}