Node* rotateLeft(Node* root);

Node * bToDLL(Node *root)
{
    Node* leftMost = rotateLeft(root);
    Node *trav = leftMost, *prev = leftMost;
    while (trav != NULL) {
        if (trav->right == NULL) break;

        trav = trav->right;
        trav->left = prev;
        prev = prev->right;
    }

    return leftMost;
}

Node* rotateLeft(Node* root) {
    if (root->right == NULL && root->left == NULL) {
        return root;
    }
    
    Node* t;
    while (root->left != NULL) {
        t = root->left;
        root->left = t->right;
        t->right = root;
        root = t;
    }

    root->right = rotateLeft(root->right);
    return root;
}

// https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1