int maxSum = 0;

int maxPathSum(Node* root)
{
    if (root == NULL) {
        return 0;
    }
    
    int leftMaxPath = maxPathSum(root->left);
    int rightMaxPath = maxPathSum(root->right);
    
    int max = leftMaxPath > rightMaxPath ? leftMaxPath : rightMaxPath;
    return root->data + max;
}

// https://practice.geeksforgeeks.org/problems/maximum-sum-leaf-to-root-path/1/