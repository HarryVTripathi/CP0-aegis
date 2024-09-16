# https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1/

from heapq import heappush, heappop, heapify
class Solution:
    #Function to return the sorted array.

    def nearlySorted(self, a, n, k):
        """
        Since elements are at most k-positions away from their
        respective positions, heapifying elements in a window of k
        will definitely return minimum element.
        """
        hq = a[0:k+1]
        res = []
        heapify(hq)
        
        for i in range(k+1, n):
            res.append(heappop(hq))
            heappush(hq, a[i])
            
        while hq:
            res.append(heappop(hq))
            
        return res
