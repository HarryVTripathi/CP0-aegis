int singleValCount = 0;

class Solution
{
    public:
    int singlevalued(Node *root)
    {
        singleValCount = 0;
        checkSingleValued(root);
        return singleValCount;
    }
    
    bool checkSingleValued(Node* root)
    {
        bool singleValueLeft = root->left == NULL ? true :
            checkSingleValued(root->left) && root->data == root->left->data;
            
        bool singleValueRight = root->right == NULL ? true :
            checkSingleValued(root->right) && root->data == root->right->data;
        
        if (singleValueLeft && singleValueRight) {
            singleValCount += 1;
            return true;
        } else {
            return false;
        }
    }
    
};

// https://practice.geeksforgeeks.org/problems/single-valued-subtree/1