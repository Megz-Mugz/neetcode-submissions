class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        res = []
        N = len(nums)
        def dfs(curr, target, index):

            if target < 0 or index >= N: return 

            if target == 0:
                res.append(curr[:])
                return
            
            # choice to take
            curr.append(nums[index])
            dfs(curr, target - nums[index], index)
            curr.pop()

            # choice not to take
            dfs(curr, target, index + 1)

            
        dfs(curr=[], target=target, index=0)
        return res