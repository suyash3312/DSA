class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void topViewPrinter(Node* root, int level, vector<int>& TopView){
        map<int, int> view;
        queue<pair<Node*, int>>q;
        q.push({root, level});
        
        while(!q.empty()){
            pair<Node*, int>temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            level = temp.second;
            if(view.find(level) == view.end()){
                view[level] = frontNode -> data;
            }
            
            if(frontNode -> left != NULL){
                q.push({frontNode -> left, level - 1});
            }
            if(frontNode -> right != NULL){
                q.push({frontNode -> right, level + 1});
            }
        }
        for(auto i : view){
            TopView.push_back(i.second);
        }
    }
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>TopView;
        int level = 0;
        topViewPrinter(root, level, TopView);
        return TopView;
    }

};