class Solution {
  public:
    Node* findTargetNodeAndCreateParentMapping(Node* root, int target, unordered_map<Node*, Node*>& ParentMap){
        queue<Node*>q;
        Node* targetNode = 0;
        q.push(root);
        ParentMap[root] = 0;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(front -> data == target){
                targetNode = front;
            }
            if(front -> left){
                ParentMap[front -> left] = front;
                q.push(front -> left);
            }
            if(front -> right){
                ParentMap[front -> right] = front;
                q.push(front -> right);
            }
        }
        return targetNode;
    }
    
    int TimeTakenToBurnTree(Node* targetNode, unordered_map<Node*, Node*>& ParentMap){
        int T = 0;
        queue<Node*>q;
        q.push(targetNode);
        unordered_map<Node*, bool>isBurnt;
        isBurnt[targetNode] = 1;
        while(!q.empty()){
            bool hasFireSpread = 0;
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node* front = q.front();
                q.pop();
                if(front -> left && !isBurnt[front -> left]){
                    hasFireSpread = 1;
                    isBurnt[front -> left] = true;
                    q.push(front -> left);
                }
                if(front -> right && !isBurnt[front -> right]){
                    hasFireSpread = 1;
                    isBurnt[front -> right] = true;
                    q.push(front -> right);
                }
                if(ParentMap[front] && !isBurnt[ParentMap[front]]){
                    hasFireSpread = 1;
                    isBurnt[ParentMap[front]] = true;
                    q.push(ParentMap[front]);
                }
            }
            if(hasFireSpread) ++T;
        }
        return T;
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*, Node*>ParentMap;
        Node* targetNode = findTargetNodeAndCreateParentMapping(root , target, ParentMap);
        return TimeTakenToBurnTree(targetNode, ParentMap);
    }
};