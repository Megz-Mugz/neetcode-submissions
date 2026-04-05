class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        number_dict = {}
        for i in range(len(nums)):
            addend = target - nums[i]
            if (addend in number_dict.keys()):
                return [number_dict[addend], i]
            else:
                number_dict[nums[i]] = i
            
