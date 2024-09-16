class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
      lf = 0
      rt = 0
      lngt = 0
      s_arr = list(s)
      s1 = set()
      
      while rt < len(s_arr):
        if s_arr[rt] in s1:
          while s_arr[lf] !=  s_arr[rt]:
            s1.discard(s_arr[lf])
            lf += 1
          
          s1.discard(s_arr[lf])
          lf += 1

        else:
          s1.add(s_arr[rt])
          rt += 1
          
        lngt = max(lngt, (rt - lf))

      return lngt

