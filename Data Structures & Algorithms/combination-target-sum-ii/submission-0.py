class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        
        candidates.sort() # [9,2,2,4,6,1,5] -> [1,2,2,4,5,6,9]
        output = []

        def dfs(index, curr_combo, total):
            nonlocal output

            if total == target:
                output.append(curr_combo[:])
                return
            
            if (total > target) or index >= len(candidates): return

            # decision to add curr index
            curr_combo.append(candidates[index])
            dfs(index + 1, curr_combo, total + candidates[index])
            curr_combo.pop()

            while index + 1 < len(candidates) and candidates[index] == candidates[index + 1]:
                index += 1
            
            # decision to NOT add curr index (you popped above)
            dfs(index + 1, curr_combo, total)


        dfs(0, [], 0)
        return output