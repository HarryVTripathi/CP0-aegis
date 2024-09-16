class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        // if (n==1) return 1;
        
        long long sum = 0;
        int res = -1;
        
        for (int i=0; i<n; i++) {
            sum += a[i];
        }
        
        long long lsum = 0;
        long long rsum = sum;

        for (int i=0; i<n; i++) {
            rsum -= a[i];

            if (lsum == rsum) {
                res = i+1;
                break;
            }
            lsum += a[i];
        }
        // Your code here
        return res;
    }

};