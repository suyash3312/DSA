class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        stack<int> st; // Monotonic stack to store indices
        vector<int> result(n, -1); // Initialize result with -1

        for(int i = 0; i < n; i++){ // Traverse the array from left to right
            // Pop elements from the stack while the element at the index stored in stack is >= current element
            while(!st.empty() && a[st.top()] >= a[i]){
                st.pop();
            }
            // If stack is not empty, the top of the stack is the index of the nearest smaller element
            if(!st.empty()){
                result[i] = a[st.top()];
            }
            // Push current index to the stack
            st.push(i);
        }
        return result;
    }
};
