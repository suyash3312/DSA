vector<int> diagonal(Node *root)
{
   // your code here
   if(root == NULL){
       return {};
   }
   queue<Node*>q;
   vector<int>diagnolNodes;
   q.push(root);
   
   while(!q.empty()){
       Node* front = q.front();
       q.pop();
       while(front != NULL){
           diagnolNodes.push_back(front -> data);
           if(front -> left != NULL){
               q.push(front -> left);
           }
           front = front -> right;
       }
   }
   return diagnolNodes;
}