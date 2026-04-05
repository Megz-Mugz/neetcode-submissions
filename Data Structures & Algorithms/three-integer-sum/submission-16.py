class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        nums.sort()
        output = []

        for i in range(len(nums)):

            if i > 0 and nums[i - 1] == nums[i]:
                continue

            left, right = i + 1, len(nums) - 1
            while left < right:

                three_sum = nums[i] + nums[left] + nums[right]
                
                if three_sum < 0:
                    left += 1
                elif three_sum > 0 :
                    right -= 1
                else:
                    output.append([nums[i], nums[left], nums[right]])
                    # move ptr to avoid infinite loop
                    left += 1
                    while nums[left] == nums[left - 1] and left < right:
                        left += 1
        
        return output
                    



