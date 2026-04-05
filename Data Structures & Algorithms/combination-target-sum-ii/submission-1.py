class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        
        candidates.sort()
        output = []
        N = len(candidates)
        
        def dfs(curr_index, subset, curr_sum):

            if curr_sum == target: 
                output.append(subset[:])
                return
            
            if curr_index >= N or curr_sum > target: return
            
            # choice to add
            subset.append(candidates[curr_index])
            dfs(curr_index + 1, subset, curr_sum + candidates[curr_index])
            subset.pop()

            # choice to add next non-duplicate element
            # [1, 1, 1, 1, 2]
            while curr_index + 1 < N and candidates[curr_index] == candidates[curr_index + 1]:
                curr_index += 1
            
            dfs(curr_index + 1, subset, curr_sum)

        dfs(0, [], 0)
        return output