class Solution {
public:
    vector<int> prevSmallerElement(vector<int> a) {
        int n = a.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && a[i] <= a[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmallerElement(vector<int> arr) {
        stack<int> st;
        vector<int> result(arr.size(), -1);
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[i] < arr[st.top()]) {
                int index = st.top();
                st.pop();
                result[index] = i;
            }
            st.push(i);
        }
        return result;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev = prevSmallerElement(heights);
        vector<int> next = nextSmallerElement(heights);
        for (int i = 0; i < heights.size(); i++) {
            if (next[i] == -1) {
                next[i] = heights.size();
            }
        }
        vector<int> area(next.size());
        for (int i = 0; i < heights.size(); i++) {
            int width = next[i] - prev[i] - 1;
            int height = heights[i];
            int currArea = width * height;
            area[i] = currArea;
        }
        int MaximumArea = INT_MIN;
        for (int i = 0; i < area.size(); i++) {
            MaximumArea = max(MaximumArea, area[i]);
        }
        return MaximumArea;
    }
};
