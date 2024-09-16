class Solution:

	# Function to find maximum
	# product subarray
  # https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1

    def maxProduct(self,arr, n):
        maxProd = -10000000
        intervalLastProd = -10000000
        intervalProd = 1
        firstNeg = False
        firstNegProd = 1
        lastPosProd = 1
        arr.append(1)
        
        if n == 1:
            return arr[0]

        for i in range(n+1):
            if arr[i] == 0 or i == n:
                if intervalProd < 0:
                    intervalLastProd = max(lastPosProd, (intervalProd/firstNegProd))


                intervalProd = 1
                firstNeg = False
                firstNegProd = 1
                lastPosProd = 1
            else:
                if intervalProd < 0 and (not firstNeg):
                    firstNegProd = intervalProd
                    firstNeg = True
                if intervalProd > 0:
                    lastPosProd = intervalProd
                intervalProd = intervalProd * arr[i]

            maxProd = max(intervalProd, maxProd, intervalLastProd)

        return int(maxProd)
