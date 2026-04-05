class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()

        length_of_array = len(nums)

        for i in range(length_of_array - 2):
            if (i > 0 and nums[i] == nums[i - 1]):
                continue

            left = i + 1
            right = length_of_array - 1

            while (left < right):
                threeSum = nums[i] + nums[left] + nums[right]
                if threeSum > 0:
                    right -= 1
                elif threeSum < 0:
                    left += 1
                else:
                    result.append([nums[i], nums[left], nums[right]])
                    left += 1
                    right -= 1
                    while (nums[left] == nums[left - 1] and left < right):
                        left += 1

                    while (nums[right] == nums[right + 1] and left < right):
                        right -= 1
        return result

