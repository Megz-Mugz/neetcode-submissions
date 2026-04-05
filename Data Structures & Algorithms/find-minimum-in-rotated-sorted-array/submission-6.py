class Solution:
    def findMin(self, nums: List[int]) -> int:
        
        left, right = 0, len(nums) - 1
        result = nums[0]

        while left <= right:

            middle = (left + right) // 2

            if nums[left] < nums[right]:
                result = min(result, nums[left])
                break

            result = min(result, nums[middle])

            if nums[middle] >= nums[left]:
                left = middle + 1
            else:
                right = middle - 1

        
        return result
