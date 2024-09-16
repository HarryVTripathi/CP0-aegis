# https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#

class Solution:

    # Function to find maximum of each subarray of size k.
    def max_of_subarrays(self, arr, n, k):
        dq = deque([0])
        res = list()
        i = 0

        while i < k:
            while dq and arr[i] > dq[0]:
                dq.popleft()

            dq.appendleft(arr[i])
            i += 1

        while i < n:
            res.append(dq[-1])

            if dq[-1] == arr[i-k] and len(dq):
                dq.pop()

            while dq and arr[i] > dq[0]:
                dq.popleft()

            dq.appendleft(arr[i])
            i += 1

        res.append(dq[-1])
        return res
