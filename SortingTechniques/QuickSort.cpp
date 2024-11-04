#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& arr, int start, int end){
    if(start >= end){
        return 0;
    }
    int count = 0;
    int pivot = arr[start];
    for(int i = start+1; i <= end; i++){
        if(pivot >= arr[i]){
            count++;
        }
    }
    int pivotIndex = count + start;
    swap(arr[start], arr[pivotIndex]);
    int i = start;
    int j = end;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[pivotIndex] > arr[i]){
            i++;
        }
        while(arr[pivotIndex] < arr[j]){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}
void quickSort(vector<int>& arr, int start, int end){
    if(start >= end){
        return;
    }
    int p = partition(arr, start, end);
    quickSort(arr, start, p-1);
    quickSort(arr, p+1, end);
}
int main() {
  vector<int>arr{10, 20, 5, 8, 3, 18, 15, 12};
  quickSort(arr, 0, arr.size()-1);
  for(int i = 0; i < arr.size(); i++){
    cout << arr[i] << " ";
  }
  return 0;
}


class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low >= high) return;
        int i = low - 1;
        int j = low;
        int pivotIndex = high;
        int pivotElement = arr[pivotIndex];
        while(j < pivotIndex){
            if(arr[j] < pivotElement){
                i++;
                swap(arr[i], arr[j]);
            }
            j++;
        }
        i++;
        swap(arr[pivotIndex], arr[i]);
        quickSort(arr, low, i-1);
        quickSort(arr, i+1, high);
    }
    
};
