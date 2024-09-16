# https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1/
class Solution:
     
    #Function to find if there exists a triplet in the 
    #array A[] which sums up to X.
    def find3Numbers(self,A, n, X):
        ans = 0
        
        A.sort()
        
        for i in range(n):
            j = i
            k = n-1
            
            if ans == 1:
                break

            while j < k:
                three_sum = A[i] + A[j] + A[k]
                if three_sum == X:
                    # print(A[i], A[j], A[k])
                    ans = 1
                    break
                
                elif three_sum < X:
                    j += 1
                
                else:
                    k -= 1
        
        return ans