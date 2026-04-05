class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        output = []
        n = len(nums)

        def dfs(index, subset, curr_sum):

            if index >= n: return
            
            if curr_sum == target:
                output.append(subset[:])
                return
                
            if curr_sum > target: 
                return
            
            # decision to add same
            subset.append(nums[index])
            dfs(index, subset, curr_sum + nums[index])
            
            # decision to add next
            subset.pop()
            dfs(index + 1, subset, curr_sum)



        dfs(0, [], 0)
        return output   