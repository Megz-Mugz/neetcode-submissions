class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        target = 0

        for i, num in enumerate(nums):
            if i > 0 and num == nums[i - 1]:
                continue
            
            # 2 ptr for remaining part of array
            left, right = i + 1, len(nums) - 1
            while left < right:
                three_sum =  num + nums[left] + nums[right]

                if three_sum > target:
                    right -= 1
                elif three_sum < target:
                    left += 1
                else:
                    res.append([nums[left], nums[right], nums[i]])
                    left += 1
                    while nums[left] == nums[left - 1] and left < right:
                        left += 1
        return res