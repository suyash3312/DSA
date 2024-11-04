class Solution {
  public:
  void BottomViewPrinter(Node* root, int level, vector<int>& BottomView){
        map<int, int> view;
        queue<pair<Node*, int>>q;
        q.push({root, level});
        
        while(!q.empty()){
            pair<Node*, int>temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            level = temp.second;
            
            view[level] = frontNode -> data;
            
            
            if(frontNode -> left != NULL){
                q.push({frontNode -> left, level - 1});
            }
            if(frontNode -> right != NULL){
                q.push({frontNode -> right, level + 1});
            }
        }
        for(auto i : view){
            BottomView.push_back(i.second);
        }
    }
    vector <int> bottomView(Node *root) {
        //Your code here
        vector<int>BottomView;
        int level = 0;
        BottomViewPrinter(root, level, BottomView);
        return BottomView;
    }
};