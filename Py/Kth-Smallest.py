# https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1/

class Solution:
    def kthSmallest(self,arr, l, r, k):
        '''
        arr : given array
        l : starting index of the array i.e 0
        r : ending index of the array i.e size-1
        k : find kth smallest element and return using this function
        '''
        l = [0 for i in range(10000)]
        
        for i in range(len(arr)):
            l[arr[i]-1] = 1
            
        # print(l)
        K = 0
        kth_smallest = 0
        for i in range(10000):
            K += l[i]
            if (K == k):
                kth_smallest = i+1
                break
        
        return kth_smallest