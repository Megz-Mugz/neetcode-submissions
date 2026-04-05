class Solution:
    def findMin(self, nums: List[int]) -> int:
        
        left, right = 0, len(nums) - 1
        result = nums[0]

        while left <= right:

            middle = (left + right) // 2

            if nums[left] <= nums[right]:
                result = min(result, nums[left])
                break
            else:
                # check to see if the middle is your min value 
                # before updating pointers
                result = min(result, nums[middle])
                # lower values are on the right side of middle, so change
                # left ptr accordingly
                if nums[middle] >= nums[left]:
                    left = middle + 1
                # 
                else: 
                    right = middle - 1

        
        return result
