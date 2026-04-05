class Solution:
    def findMin(self, nums: List[int]) -> int:
        
        left, right = 0, len(nums) - 1
        res = nums[0]

        while left <= right:

            # [4, 5, 6, 7, 1, 2, 3]

            if nums[left] < nums[right]: 
                res = min(res, nums[left])
                return res

            middle = (left + right) // 2

            res = min(res, nums[middle])

            if ( nums[left] <= nums[middle] ):
                left = middle + 1 
            else:
                right = middle - 1
        
        return res
        
