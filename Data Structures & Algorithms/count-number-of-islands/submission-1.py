class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        

        visited = set()

        def perform_dfs(row, col):
            # validate it's a legit thingy
            if not (0 <= row < len(grid)) or not (0 <= col < len(grid[0])): return 

            if (row, col) in visited: return 

            if grid[row][col] != "1": return

            visited.add((row, col))

            perform_dfs(row - 1, col)
            perform_dfs(row + 1, col)
            perform_dfs(row, col + 1)
            perform_dfs(row, col - 1)


        count = 0
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if (row, col) not in visited and grid[row][col] == "1":
                    perform_dfs(row, col)
                    count += 1

        return count

        
