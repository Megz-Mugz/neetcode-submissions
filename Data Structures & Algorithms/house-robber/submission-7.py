class Solution:
    def rob(self, houses: List[int]) -> int:
        
        NUMBER_OF_HOUSES = len(houses)
        cache = {}

        def dfs(index):
            
            if index >= NUMBER_OF_HOUSES: return 0

            if index in cache:
                return cache[index]
                
            money = houses[index]

            cache[index] = max(
                                money + dfs(index + 2), # take money and move to next "allowed" house
                                dfs(index + 1), # don't take money and move to next house
                            )
            
            return cache[index]

        return dfs(0)