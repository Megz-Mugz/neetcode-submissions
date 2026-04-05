class Solution:
    def search(self, nums: List[int], target: int) -> int:
        

        def binary_search_helper(nums, target, left, right):
            if left > right:
                return -1
            
            middle = (left + right) // 2

            if nums[middle] == target:
                return middle
            elif nums[middle] > target:
                return binary_search_helper(nums = nums, target = target, left = left, right = middle - 1)
            else:
                return binary_search_helper(nums = nums, target = target, left = middle + 1, right = right)
        
        left, right = 0, len(nums) - 1

        return binary_search_helper(nums = nums, target = target, left = left, right = right)