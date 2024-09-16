# Sorting is greedy

class Solution:    
    #Function to find the minimum number of platforms required at the
    #railway station such that no train waits.
    def minimumPlatform(self,n,arr,dep):
        maxPlat = 0
        nPlat = 0
        i = 0
        j = 0
        
        arr.sort()
        dep.sort()
        
        while i < n and j < n:
            if arr[i] <= dep[j]:
                nPlat += 1
                i += 1
                
            else:
                nPlat -= 1
                j += 1
        
            maxPlat = max(maxPlat, nPlat)
            
        return maxPlat