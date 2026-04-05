class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:

        nums_uniq = set(nums)

        if (len(nums_uniq) == len(nums)):
            return False
        else:
            return True