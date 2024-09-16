from collections import defaultdict
class Solution:
    def getSet(self, arr, n):
        memo = defaultdict(lambda: defaultdict(lambda: 0))
    
        for i in range(n):
            a = arr[i]
            for j in range(i+1, n):
                an = arr[j]
                d = arr[j] - arr[i]
                memo[an][d] = a
                pass
            
        di = { k: dict(v) for k,v in memo.items() }
        # print(di)
        return memo

    def lengthOfLongestAP(self, A, n):
        memo = self.getSet(A, n)
        
        max_len = 1
        for an, diffs in list(memo.items()):
            ap_len = 1
            
            for diff, ax in diffs.items():
                ap_len = 2
                d = diff
                ai = ax
                
                while memo[ai][d]:
                    ap_len += 1
                    ai = memo[ai][d]
                    
                max_len = max(max_len, ap_len)
        
        return max_len