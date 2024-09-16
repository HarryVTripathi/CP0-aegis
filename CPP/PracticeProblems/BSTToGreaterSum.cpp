// https://practice.geeksforgeeks.org/problems/bst-to-greater-sum-tree/1/

class Solution
{
    public:
    void transformTree(struct Node *root)
    {
        transform(root, 0);
    }
    
    int transform(struct Node* root, int val)
    {
        if (root == NULL) {
            return 0;
        }
        
        int curr = root->data;
        int rightVal = transform(root->right, val);
        root->data = rightVal + val;
        
        int leftVal = transform(root->left,  curr + root->data);
        return curr + leftVal + rightVal;
    }
};