class Solution:
    def maxSumPath(self, arr1, arr2, m, n):
        i = 0
        j = 0
        rsum = 0
        lsum = 0
        cumsum = 0

        while i < m and j < n:
            if arr1[i] < arr2[j]:
                lsum += arr1[i]
                i += 1

            elif arr1[i] > arr2[j]:
                rsum += arr2[j]
                j += 1

            else:
                lsum += arr1[i]
                rsum += arr2[j]
                cumsum += max(lsum, rsum)

                lsum = 0
                rsum = 0
                i += 1
                j += 1

        while i < m:
            lsum += arr1[i]
            i += 1

        while j < n:
            rsum += arr2[j]
            j += 1

        cumsum += max(lsum, rsum)

        return cumsum
