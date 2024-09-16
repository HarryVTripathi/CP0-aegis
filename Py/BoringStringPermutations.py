class Solution:
    def solve(self, A):
        arr = [ord(x) for x in A if x != ""]
        dist = list(set(arr))
        dist.sort()
        ans = 0

        if len(dist) < 4:
            for i in range(1, len(dist)):
                if dist[i] - dist[i-1] == 1:
                    pass
                else:
                    ans = 1
        else:
            ans = 1

        return ans