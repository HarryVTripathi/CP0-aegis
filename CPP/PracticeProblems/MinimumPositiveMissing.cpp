// https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1

class Solution
{
    public:
    int segregate(int arr[], int n) {
        int lastInd = n - 1;
        int lastSwapped = -1;
    
        for (int i=0; i<n; i++) {
            
            if (arr[i] <= 0) {
                while(arr[lastInd] <= 0 && lastInd > i) {
                    lastInd--;
                }
                
                if (arr[lastInd] > 0) {
                    int temp = arr[lastInd];
                    arr[lastInd] = arr[i];
                    arr[i] = temp;
                    lastSwapped = i;
                }
                
            }
        }
        lastSwapped = lastSwapped > 0 ? lastSwapped : n - 1;
    }

    int missingNumber(int arr[], int n) 
    { 

        int smaPosMis = 0;
        int posUpto = -1;
        segregate(arr, n);

        
        for (int i=0; i < n; i++) {
            if (arr[i] <= 0) break;
            posUpto += 1;
        }

        for (int i=0; i <= posUpto; i++) {
            int mapInd = abs(arr[i])-1;
            if (mapInd >= 0 && mapInd <= posUpto)
                if (arr[mapInd] > 0)
                    arr[mapInd] *= (-1);
        }
        
        for (int i=0; i <= posUpto; i++) {
            if (arr[i] > 0) {
                smaPosMis = i+1;
                break;
            }
            
            if (i == posUpto && smaPosMis == 0) {
                smaPosMis = posUpto+2;
            }
        }
        
        if (posUpto == -1) smaPosMis = 1;
        return smaPosMis;
    } 
};