# include <algorithm>


class Solution {
  public:


    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr+n);
        int diff = arr[n-1] - arr[0];
        
        for (int i=1; i<=n-1; i++) {
            int minHt = min(arr[0] + k, arr[i] - k);
            int maxHt = max(arr[n-1] - k, arr[i-1] + k);
            
            diff = min(diff, (maxHt-minHt));
        }
        
        
        return diff;
    }
};