class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        
        # cost = [1, 2, 3]
        
        top_floor = len(cost)


        def dfs(index):

            if index >= top_floor: return 0
            
            price_to_add = cost[index]

            return price_to_add + min(dfs(index + 1), dfs(index + 2))

        return min(dfs(index=0), dfs(index=1))