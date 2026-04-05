class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        output = []
        def dfs(i: int, curr_nums: List[int]) -> None:

            if (sum(curr_nums) > target) or i >= len(nums): return

            if sum(curr_nums) == target:
                print(curr_nums)
                output.append(curr_nums[:])
                return
            
            
            # decision TO ADD current index
            curr_nums.append(nums[i])
            dfs(i, curr_nums)

            # decision to NOT ADD current index
            curr_nums.pop()
            dfs(i + 1, curr_nums)

        
        dfs(0, [])
        return output