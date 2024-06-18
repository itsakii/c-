class Solution {
  private:
    int countNode(struct Node* root){
        if(!root) return 0;
        
        int leftCount = countNode(root->left);
        int rightCount = countNode(root->right);
        return 1 + leftCount + rightCount;
    }
    
    bool isCBT(struct Node* root, int index, int count){
        if(!root) return true;
        
        if(index >= count) return false;
        else{
            bool leftAns = isCBT(root->left, 2*index + 1, count);
            bool rightAns = isCBT(root->right, 2*index + 2, count);
            
            return leftAns && rightAns;
        }
    }
    
    bool isMaxOrder(struct Node* root){
        // leaf node is heap
        if(!root->left && !root->right) return true;
        
        if(!root->right){
            return root->data > root->left->data;
        }
        else{
            bool leftAns = isMaxOrder(root->left);
            bool rightAns = isMaxOrder(root->right);
            
            return (leftAns && rightAns && root->data > root->left->data && root->data > root->right->data);
        }
    }
  public:
    bool isHeap(struct Node* tree) {
        int index = 0;
        int count = countNode(tree);
        
        if(isCBT(tree, index, count) && isMaxOrder(tree)){
            return true;
        }
        else return false;
    }
};