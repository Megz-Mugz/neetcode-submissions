class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        if len(nums) == 0:
            return [[]]
        
        permutations = self.permute(nums[1:])
        res = []
        for permutation in permutations:
            for index in range(len(permutation) + 1):
                p_copy = permutation[:]
                p_copy.insert(index, nums[0])
                res.append(p_copy)
        return res