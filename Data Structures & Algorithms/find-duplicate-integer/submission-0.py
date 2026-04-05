class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        
        left = 0
        right = 1
        flag = True

        while flag:
            print(f"left index: {left} right index: {right}")
            print(f"left:{nums[left]} right:{nums[right]}\n")
            if (nums[left] == nums[right] and left != right):
                return nums[left]
            else:
                left += 1 
                if left >= len(nums)-1:
                    left = 0
                right += 2
                if right >= len(nums):
                    right %= len(nums)