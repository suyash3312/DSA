class Solution
{
    public:
    //Function to merge k sorted arrays.
    class Info{
        public:
        int row;
        int col;
        int data;
        
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
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int>ans;
        priority_queue<Info*, vector<Info*>, compare> pq;
        for(int row = 0; row < K; row++){
            Info* temp = new Info(arr[row][0], row, 0);
            pq.push(temp);
        }
        
        while(!pq.empty()){
            Info* topNode = pq.top();
            pq.pop();
            int data = topNode -> data;
            int rowIndex = topNode -> row;
            int colIndex = topNode -> col;
            
            ans.push_back(data);
            
            if(colIndex + 1 < arr[0].size()){
                Info* newInfo = new Info(arr[rowIndex][colIndex + 1], rowIndex, colIndex + 1);
                pq.push(newInfo);
            }
        }
        return ans;
    }
};