class Solution:
	def removeDuplicates(self,str):
	    chars = set()
	    str_cp = ""
	    
	    for i in str:
	        if i not in chars:
	            str_cp += i
	            chars.add(i)

	    return str_cp