class Solution:
    def sort012(self,arr,n):
        return self.sort(arr)
        
    def swap(self, array, i, j):
        if (i == j):
            return
        array[i] = array[i] + array[j]
        array[j] = array[i] - array[j]
        array[i] = array[i] - array[j]

    def sort(self, array):
        low = -1
        high = len(array)
    
        for i in range(len(array)):
            if (array[i] == 0):
                low += 1
            else:
                break
    
        for i in range(len(array)-1, -1, -1):
            if (array[i] == 2):
                high -= 1
            else:
                break
        
        i = low + 1
        while (i < high):
            if (array[i] == 0):
                low += 1
                self.swap(array, low, i)
                
                if (low == i):
                    i += 1
                
            elif (array[i] == 2):
                high -= 1
                self.swap(array, high, i)
                
                
            else:
                i += 1
            
        return array