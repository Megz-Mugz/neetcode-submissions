class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        for index, fixed in enumerate(nums):
            if (index > 0 and fixed == nums[index - 1]):
                continue

            left = index + 1
            right = len(nums) - 1

            while (left < right):
                threeSum = fixed + nums[left] + nums[right]

                if (threeSum < 0):
                    left += 1
                elif (threeSum > 0):
                    original_right = right
                    right -= 1
                else:
                    res.append([fixed, nums[left], nums[right]])
                    left += 1
                    # after update, check to see if one of them is a duplicate of what was already done
                    while (nums[left] == nums[left - 1] and left < right):
                        left += 1
        return res

            