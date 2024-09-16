Node* rotateRight(Node* root);

Node *bTreeToCList(Node *root)
{
    Node* rightMost = rotateRight(root);
    Node* ansNode;
    
    Node *trav = rightMost, *prev = rightMost;
    while (trav != NULL) {
        if (trav->left == NULL) {
            trav->left = rightMost;
            ansNode = trav;
            rightMost->right = trav;
            break;
        }
        
        trav = trav->left;
        trav->right = prev;
        prev = prev->left;
    }

    return ansNode;
}


Node* rotateRight(Node* root) {
    if (root->right == NULL && root->left == NULL) {
        return root;
    }
    
    Node* t;
    while (root->right != NULL) {
        t = root->right;
        root->right = t->left;
        t->left = root;
        root = t;
    }

    root->left = rotateRight(root->left);
    return root;
}

// https://practice.geeksforgeeks.org/problems/binary-tree-to-cdll/1