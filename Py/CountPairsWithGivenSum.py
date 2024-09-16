from collections import Counter, defaultdict

class Solution:
    def getPairsCount(self, arr, n, K):
        dfd = defaultdict(lambda: 0, Counter(arr))
        d = dict(dfd)
        s = set()
        count = 0
        
        for key in d.keys():
            if K == 2 * key:
                count += int((dfd[key] * (dfd[key] - 1))/2)
            else:
                if not key in s:
                    count += dfd[key] * dfd[K-key]
                    s.add(K-key)

        return count
