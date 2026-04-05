class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        output = 0

        nums = set(nums)

        for num in nums:
            
            if num - 1 not in nums: # O(1) lookup in a set
                count = 0
                i = num
                while i in nums:
                    count += 1
                    i += 1
                output = max(output, count)


        return output