class Solution{
public:
    int count = 0;
    int getCount(Node *root, int l, int h)
    {
      // your code goes here   
      if(root == NULL){
        return 0;
      }
      if(root -> data >= l && root -> data <= h){
          count++;
      }
      getCount(root -> left, l, h);
      getCount(root -> right, l, h);
      return count;
    }
};