class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size() ;
        vector<double> answer(n, -1.0);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i) {
            int position = cars[i][0];
            int speed = cars[i][1];

            while (!st.empty()) {
                int j = st.top();
                int positionAhead = cars[j][0];
                int speedAhead = cars[j][1];

                if (speed <= speedAhead || (answer[j] > 0 && (positionAhead - position) /(double)(speed - speedAhead) >=answer[j])) {
                    st.pop();
                } else {
                    answer[i] = ((positionAhead - position) /(double)(speed - speedAhead));
                    break;
                }
            }
            st.push(i);
        }
        return answer;
    }
};