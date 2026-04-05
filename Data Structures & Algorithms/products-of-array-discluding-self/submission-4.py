class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        arr = []

        for index in range(0, len(nums)):
            
            left = 0
            left_product = 1
            while left < index:
                left_product *= nums[left]
                left += 1
        
            right_product = 1
            right = index + 1
            while right < len(nums):
                right_product *= nums[right]
                right += 1
            
            arr.append(left_product * right_product)

        return arr