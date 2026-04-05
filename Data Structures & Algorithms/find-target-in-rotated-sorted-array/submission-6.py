class Solution:
    def search(self, nums: List[int], target: int) -> int:
        
        left, right = 0, len(nums) - 1

        while left <= right:

            middle = (left + right) // 2

            if nums[middle] == target:
                return middle

            # left portion is sorted
            if nums[middle] >= nums[left]:
                if target > nums[middle] or target < nums[left]:
                    left = middle + 1
                else:
                    right = middle - 1
            # right portion is sorted
            else:
                if target > nums[right] or target < nums[middle]:
                    right = middle - 1
                else:
                    left = middle + 1
        return -1
            