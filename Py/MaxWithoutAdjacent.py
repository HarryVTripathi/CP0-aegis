# https://practice.geeksforgeeks.org/problems/max-sum-without-adjacents2430/1
class Solution:
	
	def findMaxSum(self,arr, n):
	    arr.append(0)
	    
	    for i in range(n-3, -1, -1):
	        arr[i] += max(arr[i+2], arr[i+3])
	        
	    return max(arr[0], arr[1])