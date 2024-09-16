// https://practice.geeksforgeeks.org/problems/cousins-of-a-given-node/1

vector<int> g1;
int targetHeight;

void setTargetNodeHeight(Node* root, Node* nodeToFind, int height) {
  if (root == NULL) {
    return;
  }
  
  if (root == nodeToFind) {
    targetHeight = height;
  }
  
  height += 1;
  setTargetNodeHeight(root->left, nodeToFind, height);
  setTargetNodeHeight(root->right, nodeToFind, height);
}

void accumulateCousins(Node* root, Node* nodeToFind, int height) {
  if (root == NULL) {
    return;
  }

  if (height == targetHeight && height > 1) {
    g1.push_back(root->data);
  }

  if (root->left == NULL && root->right == NULL) {
    return;
  }
  
  if (root->left == nodeToFind || root->right == nodeToFind) {
    return;
  }

  accumulateCousins(root->left, nodeToFind, height+1);
  accumulateCousins(root->right, nodeToFind, height+1);
}

class Solution
{
  public:
  vector<int> printCousins(Node* root, Node* node_to_find)
  {
    targetHeight = 0;
    g1.clear();

    setTargetNodeHeight(root, node_to_find, 0);
    accumulateCousins(root, node_to_find, 0);
    
    if(g1.empty()) {
      g1.push_back(-1);
    }

    return g1;
  } 
};