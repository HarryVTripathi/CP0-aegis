#include <iostream>
// #BEST
using namespace std;

class Solution {
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    bool isMajority(int a[], int size, int majEl) {
        int majorityCount = 0;
        for (int i=0; i<size; i++) {
            if (a[i] == majEl) {
                majorityCount += 1;
            }
        }
        
        return majorityCount > size/2;
    }
    
    int majorityElement(int a[], int size)
    {
        int majorityLeadElement = -1;
        int majorityCount = 0;
        for (int i=0; i<size; i++) {
            if (a[i] != majorityLeadElement && majorityCount <= 0) {
                majorityLeadElement = a[i];
                majorityCount += 1;
            } else if (a[i] != majorityLeadElement && majorityCount > 0) {
                majorityCount -= 1;
            } else {
                majorityCount += 1;
            }
            
            // cout << majorityLeadElement << ", " << majorityCount << endl;
        }
        
        return isMajority(a, size, majorityLeadElement) ? majorityLeadElement : -1;
    }
};

// 8
// 4 4 6 4 6 4 6 3

// 8
// 4 4 6 4 6 4 6 4