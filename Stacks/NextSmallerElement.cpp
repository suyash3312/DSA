//GFG -  HELP CALSSMATES
class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        stack<int> st;
        vector<int> result(arr.size(), -1);
        for(int i=0; i<arr.size(); i++){
            while(!st.empty() && arr[i] < arr[st.top()]){
                int index = st.top();
                st.pop();
                result[index] = arr[i];
            }
            st.push(i);
        }
        return result;
    } 
};