class Solution:
	def pushZerosToEnd(self,arr, n):
	    ptr_0 = 0
	    ptr_n = 0
	    count_pos = 0
	    
	    for i in range(n):
	        arr[count_pos] = arr[i]
	        if arr[i] > 0:
	            count_pos += 1
	            
	    for i in range(count_pos, n):
	        arr[i] = 0

	    return arr