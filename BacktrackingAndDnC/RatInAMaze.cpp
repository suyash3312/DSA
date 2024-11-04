#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int arr[][4], int row, int col, int srcx, int srcy, string& output, vector<vector<bool>>& visited){
  //OUT OF BOUNDS
  //VISTED OR NOT
  //PATH OPEN OR CLOSED
  if((srcx >= 0 && srcx < row) && 
    (srcy >= 0 && srcy < col) && 
    (visited[srcx][srcy] == false) && 
    (arr[srcx][srcy] == 1)){
    return true;
  }  
  else{
    return false;
  }
}
void RatInAMaze(int arr[][4], int row, int col, int srcx, int srcy, string& output, vector<vector<bool>>& visited){
  //BASE CASE
  if(srcx == row - 1 && srcy == col - 1){
    cout << output << " ";
    return;
  }
  //UP
  int newx = srcx - 1;
  int newy = srcy;
  if(isSafe(arr, row, col, newx, newy, output, visited)){
    visited[newx][newy] = true;
    output.push_back('U');
    RatInAMaze(arr, row, col, newx, newy, output, visited);
    visited[newx][newy] = false;
    output.pop_back();
  }
  
  //DOWN
  newx = srcx + 1;
  newy = srcy;
  if(isSafe(arr, row, col, newx, newy, output, visited)){
    visited[newx][newy] = true;
    output.push_back('D');
    RatInAMaze(arr, row, col, newx, newy, output, visited);
    visited[newx][newy] = false;
    output.pop_back();
  }
  

  //RIGHT
  newx = srcx;
  newy = srcy + 1;
  if(isSafe(arr, row, col, newx, newy, output, visited)){
    visited[newx][newy] = true;
    output.push_back('R');
    RatInAMaze(arr, row, col, newx, newy, output, visited);
    visited[newx][newy] = false;
    output.pop_back();
  }
  

  //LEFT
  newx = srcx;
  newy = srcy - 1;
  if(isSafe(arr, row, col, newx, newy, output, visited)){
    visited[newx][newy] = true;
    output.push_back('L');
    RatInAMaze(arr, row, col, newx, newy, output, visited);
    visited[newx][newy] = false;
    output.pop_back();
  }
  
}
int main() {
  int arr[4][4] ={{1, 1, 1, 1},
                 {1, 1, 1, 1}, 
                 {1, 1, 1, 1},
                 {1, 1, 1, 1}};
                 
  int row = 4;
  int col = 4;
  vector<vector<bool>> visited(row, vector<bool>(col, false));
  int srcx = 0;
  int srcy = 0;
  visited[srcx][srcy] = true;
  string output = "";
  RatInAMaze(arr, row, col,  srcx,  srcy, output, visited);
  return 0;
}


// class Solution {
//   public:
//   vector<string>result;
//   bool isSafe(vector<vector<int>>arr, int row, int col, int srcx, int srcy, string& output, vector<vector<bool>>& visited){
//   //OUT OF BOUNDS
//   //VISTED OR NOT
//   //PATH OPEN OR CLOSED
//   if((srcx >= 0 && srcx < row) && 
//     (srcy >= 0 && srcy < col) && 
//     (visited[srcx][srcy] == false) && 
//     (arr[srcx][srcy] == 1)){
//     return true;
//   }  
//   else{
//     return false;
//   }
// }
// void RatInAMaze(vector<vector<int>>arr, int row, int col, int srcx, int srcy, string& output, vector<vector<bool>>& visited){
//   //BASE CASE
//   if(srcx == row - 1 && srcy == col - 1){
//     result.push_back(output);
//     return;
//   }
//   //UP
//   int newx = srcx - 1;
//   int newy = srcy;
//   if(isSafe(arr, row, col, newx, newy, output, visited)){
//     visited[newx][newy] = true;
//     output.push_back('U');
//     RatInAMaze(arr, row, col, newx, newy, output, visited);
//     visited[newx][newy] = false;
//     output.pop_back();
//   }
  
//   //DOWN
//   newx = srcx + 1;
//   newy = srcy;
//   if(isSafe(arr, row, col, newx, newy, output, visited)){
//     visited[newx][newy] = true;
//     output.push_back('D');
//     RatInAMaze(arr, row, col, newx, newy, output, visited);
//     visited[newx][newy] = false;
//     output.pop_back();
//   }
  

//   //RIGHT
//   newx = srcx;
//   newy = srcy + 1;
//   if(isSafe(arr, row, col, newx, newy, output, visited)){
//     visited[newx][newy] = true;
//     output.push_back('R');
//     RatInAMaze(arr, row, col, newx, newy, output, visited);
//     visited[newx][newy] = false;
//     output.pop_back();
//   }
  

//   //LEFT
//   newx = srcx;
//   newy = srcy - 1;
//   if(isSafe(arr, row, col, newx, newy, output, visited)){
//     visited[newx][newy] = true;
//     output.push_back('L');
//     RatInAMaze(arr, row, col, newx, newy, output, visited);
//     visited[newx][newy] = false;
//     output.pop_back();
//   }
  
// }
//     vector<string> findPath(vector<vector<int>> &mat) {
//         // Your code goes here
//         int row = mat.size();
//         int col = mat[0].size();
//         string output = "";
//         int srcx = 0;
//         int srcy = 0;
//         vector<vector<bool>>visited(row, vector<bool>(row, false));
//         visited[srcx][srcy] = true;
//         if(mat[0][0] == 0 || mat[row-1][col-1] == 0){
//             result.push_back("-1");
//         } 
//         else{
//         RatInAMaze(mat, row, col, srcx, srcy, output, visited);
        
//         }
//         return result;
//     }
// };
