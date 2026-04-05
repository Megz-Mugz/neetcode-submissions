class Solution:
    def findMin(self, nums: List[int]) -> int:
        
        left, right = 0, len(nums) - 1
        result = nums[0]

        while left <= right:

            middle = (left + right) // 2

            result = min(result, nums[middle])

            # if val at left is greater than right side value, 
            # then the array isn't even sorted, fix that issue first
            if nums[left] > nums[right]:
                left = left + 1
            # if it is sorted, then you can work with something meaningful
            else:
                right = middle - 1
        
        return result
