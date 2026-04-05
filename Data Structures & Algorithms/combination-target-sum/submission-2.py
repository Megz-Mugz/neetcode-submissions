class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        output = []

        def dfs(i: int, curr_nums: List[int], total: int) -> None:
            
            if total > target or i >= len(nums): return

            if total == target:
                print(curr_nums)
                output.append(curr_nums[:])
                return
            
            # decision TO ADD current index
            curr_nums.append(nums[i])
            dfs(i, curr_nums, total + nums[i])

            # decision to NOT ADD current index & instead add next index
            curr_nums.pop()
            dfs(i + 1, curr_nums, total)

        
        dfs(0, [], 0)
        return output