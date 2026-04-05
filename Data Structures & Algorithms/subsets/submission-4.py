class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        
        n = len(nums)
        output = []

        def dfs(index, curr_array):

            if index >= n: 
                output.append(curr_array[:])
                return
            
            # add to the curr array
            curr_array.append(nums[index])
            dfs(index + 1, curr_array)
            print(curr_array.pop())

            # NOT add to the curr array
            dfs(index + 1, curr_array)


        dfs(0, [])
        return output
        