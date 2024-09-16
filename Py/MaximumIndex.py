class Solution:
    #Complete this function
    # Function to find the maximum index difference.
    def getMaxDiff(self, arr, indDiff):
        if (indDiff == 0):
            return indDiff

        maxIndDiff = 0
        for i in range(self.L - (indDiff - 1)):
            if arr[i+indDiff] - arr[i] >= 0:
                maxIndDiff = indDiff
    
        return maxIndDiff if maxIndDiff > 0 else self.getMaxDiff(arr, indDiff-1)
    
    def maxIndexDiff(self, arr, n):
        self.L = n-1
        
        return self.getMaxDiff(arr, n-1)
        
        ##Your code here