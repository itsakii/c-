class Solution
{
    public:
    void in(Node *root, vector<int> &v)
    {
        if (root==NULL)
        return;
        in(root->left, v);
        v.push_back(root->data);
        in(root->right, v);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
      
       vector<int> v;
       in(root1, v);
       in(root2, v);
       sort(v.begin(),v.end());
       return v;
    }
};
