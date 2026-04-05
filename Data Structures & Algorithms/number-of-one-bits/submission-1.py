class Solution:
    def hammingWeight(self, n: int) -> int:
        
        binary_rep = bin(n)
        count = 0
        for num in binary_rep:
            try:
                if int(num) == 1:
                    count += 1
            except:
                continue
        return count