#include <iostream>
using namespace std;



class Solution{
  public:    
    long long int mergeSorted(long long arr[], long long startInd, long long mid, long long endInd) {
        vector<long long> L (arr + startInd, arr + mid + 1 );
        vector<long long> R (arr + mid + 1, arr + endInd + 1 );

        long long int i = L.size()-1; long long int j = R.size()-1; long long int k = endInd;
        long long int displaceCount = 0; long long int totalInversions = 0;
        
        while (i >= 0 && j >= 0) {
            // cout << L[i]  << " vs " << R[j] << endl;
            if (L[i] > R[j]) {
                arr[k] = L[i];
                i--;
                displaceCount += 1;
            } else {
                arr[k] = R[j];
                totalInversions += displaceCount;
                j--;
            }
            k--;
        }
        
        while (i >= 0) {
            arr[k] = L[i];
            i--;
            k--;
        }
        
        while (j >= 0) {
            arr[k] = R[j];
            totalInversions += displaceCount;
            j--;
            k--;
        }
        
        return totalInversions;
    }
    
    long long int mergeSort(long long arr[], long long startInd, long long endInd) {
        if (startInd == endInd) {
            return 0;
        }
        
        long long int mid = (startInd + endInd) / 2;
        long long int a = mergeSort(arr, startInd, mid); // after calling this [start, mid] will be sorted and return the count of inversions to sort.
        long long int b = mergeSort(arr, mid+1, endInd);
        
        long long int c = mergeSorted(arr, startInd, mid, endInd);
        
        return (a + b + c);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        return  mergeSort(arr, 0, N-1);
        // Your Code Here
    }

};


// 9
// 9 8 7 6 5 4 3 2

// 3
// 10 10 10

// 9
// 5 5 9 9 9 1 1 1 6

// 9
// 1 1 1 1 1 1 1 1 1

// 17
// 1 9 2 8 3 7 4 6 5 6 4 7 8 3 9 2 1