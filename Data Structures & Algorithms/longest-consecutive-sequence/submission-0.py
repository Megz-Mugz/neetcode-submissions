class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        uniq_nums = set(nums)
        longest_streak = 0

        for num in nums:
            # left neighbor
            left_neighbor = num - 1

            if left_neighbor not in uniq_nums:
                i = num
                streak = 0
                while i in uniq_nums:
                    streak += 1
                    i += 1
                print(f'streak is {streak}')
                longest_streak = max(longest_streak, streak)
                print(f'longest streak is {longest_streak}')
        return longest_streak
