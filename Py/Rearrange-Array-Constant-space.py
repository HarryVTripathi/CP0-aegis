# https://practice.geeksforgeeks.org/problems/rearrange-an-array-with-o1-extra-space3142/1

class Solution:
    #Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    #with O(1) extra space.
    def arrange(self,arr, n):
        a = 1
        
        while a < n:
            a *= 10
        
        for i in range(n):
            if arr[arr[i]] <= n:
                arr[i] += arr[arr[i]] * a
            else:
                arr[i] += (arr[arr[i]] % a) * a
        
        for i in range(n):
            arr[i] = int(arr[i]/a)