# https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1
from collections import defaultdict, Counter
class Solution:
    #Function to count subarrays with sum equal to 0.
    def findSubArrays(self,arr,n):
        r = 2 if n < 2 else n
        fact = [0 for i in range(r+1)]
        fact[2] = 1
        
        for i in range(3, r+1):
            fact[i] = (i * (i-1)) // 2
        
        cumm = [0 for i in arr]
        summ = 0
        
        for i in range(0, n):
            summ += arr[i]
            cumm[i] = summ
        
        d = dict(Counter(cumm))
        # print(d)
        
        count = 0
        for k, v in d.items():
            if k == 0:
                count += v
                
            count += fact[v]
        
        return count