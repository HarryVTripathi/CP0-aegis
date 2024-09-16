// 20 8 22 5 3 4 25 1 N 10 14 6 7 N 9
// 20 8 22 5 3 4 25 1 33 10 14 6 7 36 9
// 1 2 8 3 N N N 4 7 5 6 N N => 5 4 6 7 1 8 
// 1 2 8 3 N N N 4 7 5 6 12 10
// 1 2 8 3 N N N 4 7 5 6 N 10
// 14 14 3 N 8 8 12 N 6 17 3 N 1 11 10 N 6 6 13 N 10 17 7 N 11 7

#include <bits/stdc++.h>
using namespace std;

// key = depth * 100 + lvl
class OrdNode {

  public:
    int ordKey;
    int val;

    OrdNode(int orderKey, int value) {
        ordKey = orderKey;
        val = value;
    }
};

struct comp
{
    template<typename T>
    bool operator()(const T &l, const T &r) const
    {
        return (l.second)->ordKey < (r.second)->ordKey;
    }
};

int orderId;
unordered_map<int, OrdNode*> m; 
vector<int> bottomNodes;
unordered_map<Node* , int> heights;

int getHeight(Node *root) {
    if (root == NULL) {
        return 0;
    }
    
    heights[root] = 1+max(getHeight(root->left), getHeight(root->right));
    
    return heights[root];
}

void traverseTree(Node *root, int level, int depth) {
    if (root == NULL) {
        return;
    }
    
    traverseTree(root->left, level-1, depth+1);
    
    int height = getHeight(root);
    int key = depth * 100 + level;
    
    if (height >= 0 && height <= 2) {
        // cout << "key: " << key << ", data: " << root->data << endl;
        m[key] = new OrdNode(orderId, root->data);;
        orderId++;
    }
    
    traverseTree(root->right, level+1, depth+1);
}


//Function to return a list containing the bottom view of the given tree.
vector <int> bottomView(Node *root)
{
    orderId = 0;
    m.clear();
    heights.clear();
    bottomNodes.clear();
    int depth = 100000;
    int level = 50;
    
    traverseTree(root, level, depth);
    
    set<pair<int, OrdNode*>, comp> set(m.begin(), m.end());
    
    for (auto const &pair: set) {
        bottomNodes.push_back((pair.second)->val);
    }

    return bottomNodes;
}

