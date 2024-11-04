class Solution {
public:
    class Info{
        public:
        int data;
        int row;
        int col;

        Info(int data, int row, int col){
            this -> data = data;
            this -> row = row;
            this -> col = col;
        }
    };

    class compare{
        public:
        bool operator()(Info* a, Info* b){
            return a -> data > b -> data;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, compare> pq;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int row = 0; row < nums.size(); row++){
            int element = nums[row][0];
            Info* temp = new Info(element, row, 0);
            pq.push(temp);
            mini = min(mini, element);
            maxi = max(maxi, element);
        }

        int start = mini;
        int end = maxi;

        while(!pq.empty()){
            Info* topNode = pq.top();
            pq.pop();
            int data = topNode -> data;
            int rowIndex = topNode -> row;
            int colIndex = topNode -> col;

            mini = topNode -> data;

            if((maxi - mini) < (end - start)){
                start = mini;
                end = maxi;
            }
            if(colIndex + 1 < nums[rowIndex].size()){
                int element = nums[rowIndex][colIndex + 1];
                maxi = max(maxi, element);
                Info* newInfo = new Info(element, rowIndex, colIndex + 1);
                pq.push(newInfo);
            }
            else{
                break;
            }
        }
        vector<int>ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};