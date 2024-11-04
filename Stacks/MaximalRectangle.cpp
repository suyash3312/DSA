class Solution {
public:
    vector<int> prevSmallerIndex(vector<int> elements) {
        stack<int> st;
        vector<int> result(elements.size(), -1);
        for (int i = 0; i < elements.size(); i++) {
            while (!st.empty() && elements[i] < elements[st.top()]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top();
            }
            st.push(i);
        }
        return result;
    }
    vector<int> nextSmallerIndex(vector<int> elements) {
        stack<int> st;
        vector<int> result(elements.size(), elements.size());
        for(int i = 0; i < elements.size(); i++){
            while(!st.empty() && elements[i] < elements[st.top()]){
                int index = st.top();
                st.pop();
                result[index] = i;
            }
            st.push(i);
        }
        return result;
    }
    int MaximumRectangularArea(vector<int> heights) {
        vector<int> prev = prevSmallerIndex(heights);
        vector<int> next = nextSmallerIndex(heights);
        vector<int> Area(next.size());
        for (int i = 0; i < heights.size(); i++) {
            int width = next[i] - prev[i] - 1;
            int height = heights[i];
            int area = width * height;
            Area.push_back(area);
        }
        int maxArea = INT_MIN;
        for (int i = 0; i < Area.size(); i++) {
            maxArea = max(Area[i], maxArea);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        vector<vector<int>> v;
        for(int i = 0; i < rowSize; i++){
            vector<int>t;
            for(int j = 0; j < colSize; j++){
                t.push_back(matrix[i][j] - '0');
            }
            v.push_back(t);
        }
        int area = MaximumRectangularArea(v[0]);
        for(int i = 1; i < rowSize; i++){
            for(int j = 0; j < colSize; j++){
                if(v[i][j] != 0){
                    v[i][j] = v[i][j] + v[i-1][j];
                }
                else{
                    v[i][j] = 0;
                }
            }
            area = max(MaximumRectangularArea(v[i]), area);
        }
        return area;
    }
};