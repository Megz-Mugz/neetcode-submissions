class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        visited = {}
        for i in range(len(nums)):
            # print(i)
            # visited.update({nums[i]: i})
            addend = target - nums[i]
            if (addend in visited):
                return [visited[addend], i]
            elif(not (nums[i] in visited)):
                visited.update({nums[i] : i})