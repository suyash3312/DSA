class Solution {
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    // int c = 0;
    // void merge(vector<long long> &arr, int start, int end){
    //     int mid = (start + end)/2;
    //     int leftSize = mid - start + 1;
    //     int rightSize = end - (mid+1) + 1;
    //     vector<long long>left(leftSize , 0);
    //     vector<long long>right(rightSize, 0);
    //     int index = start;
    //     for(int i = 0; i < leftSize; i++){
    //         left[index] = arr[index];
    //         index++;
    //     }
    //     index = mid + 1;
    //     for(int i = 0; i < rightSize; i++){
    //         right[i] = arr[index];
    //         index++;
    //     }
    //     int leftArrayIndex = 0;
    //     int rightArrayIndex = 0;
    //     int mainArrayIndex = start;
    //     while(leftArrayIndex < leftSize && rightArrayIndex < rightSize){
    //         if(left[leftArrayIndex] < right[rightArrayIndex]){
    //             arr[mainArrayIndex] = left[leftArrayIndex];
    //             mainArrayIndex++;
    //             leftArrayIndex++;
    //         }
    //         else{
    //             arr[mainArrayIndex] = right[rightArrayIndex];
    //             mainArrayIndex++;
    //             rightArrayIndex++;
    //             c++;
    //         }
    //     }
    //     while(leftArrayIndex < leftSize){
    //         arr[mainArrayIndex] = left[leftArrayIndex];
    //         mainArrayIndex++;
    //         leftArrayIndex++;
    //     }
    //     while(rightArrayIndex < rightSize){
    //         arr[mainArrayIndex] = right[rightArrayIndex];
    //         mainArrayIndex++;
    //         rightArrayIndex++;
    //     }
    // }
    
    // void mergeSort(vector<long long> &arr, int start, int end){
    //     if(start >= end){
    //         return;
    //     }
    //     int mid = (start + end ) / 2;
    //     mergeSort(arr, start, mid);
    //     mergeSort(arr, mid + 1, end);
    //     merge(arr, start, end);
    // }
//     int c = 0;
// void merge(vector<long long> &arr, int s, int e){
//   int mid=(s+e)/2;
//   int lenLeft=mid-s+1;
//   int lenRight=e-(mid+1)+1;

//   int* leftArray=new int[lenLeft];
//   int* rightArray=new int[lenRight];

//   int leftArrayIndex=0;
//   int rightArrayIndex=0;
//   //yahi pr galti hogi
//   int mainArrayIndex=s;

//   int k=s;
//   for(int i=0; i<lenLeft; i++){
//     leftArray[i]=arr[k];
//     k++;
//   }
//   k=mid+1;
//   for(int i=0; i<lenRight; i++){
//     rightArray[i]=arr[k];
//     k++;
//   }

//   while(leftArrayIndex < lenLeft && rightArrayIndex < lenRight){
//     if(leftArray[leftArrayIndex] < rightArray[rightArrayIndex]){
//       arr[mainArrayIndex]=leftArray[leftArrayIndex];
//       leftArrayIndex++;
//       mainArrayIndex++;
      
//     }
//     else{
//       arr[mainArrayIndex]=rightArray[rightArrayIndex];
//       rightArrayIndex++;
//       mainArrayIndex++;
//       c+=(lenLeft - leftArrayIndex);
//     }
//   }
//   while(leftArrayIndex < lenLeft){
//     arr[mainArrayIndex]=leftArray[leftArrayIndex];
//     leftArrayIndex++;
//     mainArrayIndex++;
//   }
//   while(rightArrayIndex < lenRight){
//     arr[mainArrayIndex]=rightArray[rightArrayIndex];
//     rightArrayIndex++;
//     mainArrayIndex++;
    
//   }
//   delete[] rightArray;
//   delete[] leftArray;
// }

// void mergeSort(vector<long long> &arr, int s, int e){
//   if(s>=e){
//     return;
//   }
//   int mid=(s+e)/2;
//   mergeSort(arr, s, mid);
//   mergeSort(arr, mid+1, e);
//   merge(arr, s, e);
// }
// long long int inversionCount(vector<long long> &arr) {
//         // Your Code Here
//         mergeSort(arr, 0, arr.size() - 1);
//         return c;
//     }
 int c = 0;

    void merge(vector<long long> &arr, int start, int mid, int end){
        int leftSize = mid - start + 1;
        int rightSize = end - mid;
        vector<long long> left(leftSize, 0);
        vector<long long> right(rightSize, 0);

        // Copy data to temporary subarrays
        for (int i = 0; i < leftSize; i++) {
            left[i] = arr[start + i];
        }
        for (int i = 0; i < rightSize; i++) {
            right[i] = arr[mid + 1 + i];
        }

        int leftArrayIndex = 0, rightArrayIndex = 0;
        int mainArrayIndex = start;

        // Merge the two subarrays
        while (leftArrayIndex < leftSize && rightArrayIndex < rightSize) {
            if (left[leftArrayIndex] <= right[rightArrayIndex]) {
                arr[mainArrayIndex] = left[leftArrayIndex];
                leftArrayIndex++;
            } else {
                arr[mainArrayIndex] = right[rightArrayIndex];
                rightArrayIndex++;
                // Count inversions: All remaining elements in the left array are greater than rightArray[rightArrayIndex]
                c += (leftSize - leftArrayIndex);
            }
            mainArrayIndex++;
        }

        // Copy the remaining elements of left[] if any
        while (leftArrayIndex < leftSize) {
            arr[mainArrayIndex] = left[leftArrayIndex];
            leftArrayIndex++;
            mainArrayIndex++;
        }

        // Copy the remaining elements of right[] if any
        while (rightArrayIndex < rightSize) {
            arr[mainArrayIndex] = right[rightArrayIndex];
            rightArrayIndex++;
            mainArrayIndex++;
        }
    }

    void mergeSort(vector<long long> &arr, int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }

    long long int inversionCount(vector<long long> &arr) {
        mergeSort(arr, 0, arr.size() - 1);
        return c;
    }

};