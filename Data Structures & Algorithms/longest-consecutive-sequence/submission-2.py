class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        index = 0
        nums = list(set(nums))
        longest = 0
        for idx in range(len(nums)):

            focus_idx = idx
            sequence = 1
            while nums[focus_idx]+1 in nums:
                sequence += 1
                focus_idx = nums.index(nums[focus_idx]+1)
            
            longest = max(longest, sequence)
            
        return longest