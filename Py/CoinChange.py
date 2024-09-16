class Solution:
    def getCount(self, S, n, start, end, cent_sum):
        if cent_sum > n:
            return 0

        if self.memo[start][cent_sum] > 0:
            return self.memo[start][cent_sum]

        # print("Start: %s, cent_sum: %s " %(start, cent_sum))

        if cent_sum == n:
            self.memo[start][cent_sum] += 1
            return 1

        ans = 0
        for i in range(start, end):
            ans += self.getCount(S, n, i, end, cent_sum + S[i])

        self.memo[start][cent_sum] = ans
        return ans

    def count(self, S, m, n):
        self.memo = [[0 for i in range(n+1)] for i in range(m+1)]
        count = self.getCount(S, n, 0, m, 0)

        return count
