class Solution:
    ##Complete this function
    #Function to find the sum of contiguous subarray with maximum sum.
    def maxSubArraySum(self,a,size):
        max_sum = -100000000
        
        startInd = 0
        cumSum = 0
    
        for i in range(size):
            if a[i] > cumSum and cumSum < 0:
                cumSum = a[i]
            else:
                cumSum += a[i]

            max_sum = max(max_sum, cumSum)
            
        return max_sum