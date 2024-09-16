# https://practice.geeksforgeeks.org/problems/min-cost-climbing-stairs/1#
class Solution:
    def minCostClimbingStairs(self, cost, N):
        cost_ = 0
        
        i = N - 3
        
        while i >= 0:
            cost[i] = cost[i] + min(cost[i+1], cost[i+2])
            i -= 1
            
        # print(cost)
        return min(cost[0], cost[1])
