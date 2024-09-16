// 1 2 3 4 5 N 6 8 9 N N N N 10 11 13 14
// 1 2 N 3 N 4 N 5 N
#include <string>
#include <unordered_map>
#include <map>
//  The map is actually a tree, and is sorted by KEY order.

/* 
  An unordered_map is a hash container, that is, the keys are hashed. 
  Inside of the container, they don't have the same representation as on the outside.
  Even the name implies that you can't sort it.
*/

/**
  Algorithm: Generate keys Left_Level:Depth:Order_in_BFS and sort by the keys.
*/

class Solution
{
    public:
    int n_zero = 6;
    int order_key;
    map<string, int> umap;

    /**
      Convert a string, append with zeros. Ex: 45 => 000045
    */
    string stringifill(string s) {
        if (s.length() < n_zero) {
            s = string(n_zero - s.length(), '0') + s;
        }
        return s;
    }
    
    string generateKey(int left_depth_key, int height_key) {
        string key_prefix = stringifill(to_string(left_depth_key));
        string key_mid = stringifill(to_string(height_key));
        string key_suffix = stringifill(to_string(order_key));
        string key = key_prefix + key_mid + key_suffix;
        
        return key;
    }
    
    void iter_map() {
        // map<string, int>::iterator it = umap.begin();
        // while(it != umap.end())
        // {
        //     std::cout<<it->first << " :: "<<it->second<<std::endl;
        //     it++;
        // }
        
        // for (auto i = m.begin(); i != m.end(); i++)
        //     cout << i->first << "      " << i->second << endl;
        
        for (auto& it: umap) {
          cout << it.first << endl;
        }
    }
    
    
    void map_key_node(Node* root, int left_depth_key, int height_key) {
        if (root == NULL) {
            return;
        }

        string key = generateKey(left_depth_key, height_key);
        // cout << "Key: " << key << "  data: " << root->data << endl;
        
        umap[key] = root->data;
        order_key--;
        
        map_key_node(root->left, left_depth_key+1, height_key-1);
        map_key_node(root->right, left_depth_key-1, height_key-1);
    }

    vector<int> verticalOrder(Node *root)
    {
        vector<int> g1;
        int left_depth_key = 100000;
        int height_key = 100000;
        order_key = 100000;
        umap.clear();
        
        map_key_node(root, left_depth_key, height_key);
        
        for (auto& it: umap) {
        //   cout << it.first << endl;
          g1.push_back(it.second);
        }
        
        reverse(g1.begin(), g1.end());

        // int a = 10;
        // string s = to_string(a);
        // cout << s << endl;
        // cout << "string: " << s << endl;
        // cout << "new_string: " << stringifill(s) << endl;

        // if (s > stringifill(s)) cout << "Yes";

        //Your code here
        return g1;
    }
};