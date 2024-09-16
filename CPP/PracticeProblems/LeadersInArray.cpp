#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> leadElements;
        stack<int> s;
        
        for (int i=0; i<n; i++) {
            while(!s.empty() && a[i] > s.top()) {
                s.pop();
            }
            
            s.push(a[i]);
        }
        
        while(!s.empty()) {
            // cout << s.top() << endl;
            leadElements.push_back(s.top());
            s.pop();
        }
        
        reverse(leadElements.begin(), leadElements.end());
        
        return leadElements;
        
    }
};