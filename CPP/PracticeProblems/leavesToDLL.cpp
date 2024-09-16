#include <queue>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *left,*right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

int traverseAndTrim(Node* root, queue<Node*>* Q) {
    if (root->left == NULL && root->right == NULL) {
        Q->push(root);
        return 1;
    }
    
    if (root->left != NULL && traverseAndTrim(root->left, Q))
        root->left = NULL;
    
    if (root->right != NULL && traverseAndTrim(root->right, Q))
        root->right = NULL;
    
    return 0;
}

Node* convertToDLL(Node *root){
    queue <Node*> nodeQ;
    traverseAndTrim(root, &nodeQ);
    
    Node* head = NULL;
    Node* curr;
    
    while (!nodeQ.empty()) {
        if (head == NULL) {
            curr = head = nodeQ.front();
        }
        
        nodeQ.pop();
        
        if (!nodeQ.empty()) {
            curr->right = nodeQ.front();
            curr->right->left = curr;
            curr = curr->right;
        }
    }
    return head;
}

// https://practice.geeksforgeeks.org/problems/leaves-to-dll/1/