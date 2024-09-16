class Solution{
  public:
    int bLastInd;
    int binarySearch(int a[], int value, int start, int end) {
        int mid = (start + end) / 2;
        
        if (a[mid] == value) {
            return mid;
        }
        
        if (start == end) {
            return -1;
        }
        
        if (a[mid] > value) {
            return binarySearch(a, value, start, mid-1);
        }
        
        if (a[mid] < value) {
            return binarySearch(a, value, mid+1, end);
        }
    }

    int missingSearch(int a[], int b[], int start, int end) {
        int mid = (start + end) / 2;
        int midInSecond = binarySearch(b, a[mid], start, end-1);
        
        if (midInSecond == -1) {
            // cout << "Missing: " << a[mid] << endl;
            return mid;
        }
        
        if (midInSecond == mid) {
            if (midInSecond == bLastInd) {
                return mid+1;
            } else {
                return missingSearch(a, b, mid, end);
            }
        }
        
        if (midInSecond < mid) {
            if (midInSecond == 0) {
                return 0;
            } else {
                return missingSearch(a, b, start, mid);   
            }
        }
    }

    int findExtra(int a[], int b[], int n) {
        bLastInd = n-2;
        // add code here.
        if (n == 1) {
            return 0;
        }
        // cout << binarySearch(b, 1, 0, n-2) << endl;
        return missingSearch(a, b, 0, n-1);
    }
};

// 2
// 1 2
// 1


// 2
// 1 2
// 2

// 8
// 2 4 6 8 9 12 15 16 
// 4 6 8 9 12 15 16

// 11
// 2 4 6 8 9 12 15 16 18 20 24 
// 2 4 6 8 9 12 15 18 20 24

// 7
// 20 38 52 54 59 69 88
// 20 38 52 54 59 69
