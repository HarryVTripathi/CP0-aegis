// https://practice.geeksforgeeks.org/problems/index-of-an-extra-element/1/

class Solution{
  public:
    int findEx(int a[], int b[], int start, int end) {
        int mid = (start + end)/2;
        
        // cout << a[mid] << endl;
        if (a[mid] == b[mid]) {
            // cout << a[mid] << endl;
            return findEx(a, b, mid+1, end);
        } else {
            if (mid == 0) {
                return mid;
            } else if (a[mid-1] == b[mid-1]) {
                return mid;
            } else {
                return findEx(a, b, start, mid-1);
            }
        }
    }

    int findExtra(int a[], int b[], int n) {
        int ans = findEx(a, b, 0,  n-1);
        
        return ans;
        // add code here.
    }
};
