class Solution:
    def get(self, Matrix, r, c):
        res = 0
        try:
            res = Matrix[r][c]
        except:
            IndexError
        finally:
            return res
            
    def getMaxPath(self, M, N):
        for i in range(N-1, -1, -1):
            for j in range(N-1, -1, -1):
                x = self.get(M, i+1, j)
                y = self.get(M, i+1, j+1)
                z = self.get(M, i+1, j-1)

                M[i][j] += max(x, y, z)
                
        return M
        
    def getMax(self, M, N):
        pass
    
    def maximumPath(self, N, Matrix):
        M = self.getMaxPath(Matrix, N)

        return max(M[0])