class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        index = 0
        num_set = list(set(nums))
        longest = 0
        for num in num_set:

            if num - 1 not in num_set:
                current_num = num
                sequence = 1
                while current_num+1 in num_set:
                    sequence += 1
                    current_num += 1
                
                longest = max(longest, sequence)
            
        return longest