class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        
        output = []

        def dfs(i: int, curr_path: List[int]) -> None:

            if (i >= len(nums)):
                output.append(curr_path[:])
                return
            
            # decision to add to 
            curr_path.append(nums[i])
            dfs(i + 1, curr_path)
            
            # note: you can't pop from empty array, so you need to make "adding" element decision first, 
            # and then make the decision to "not add"

            # decision to NOT add
            curr_path.pop()
            dfs(i + 1, curr_path)


        dfs(0, [])
        return output