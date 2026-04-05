class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        # guard clause
        if not grid: return 0

        visited = set()
        num_of_islands = 0

        NUM_ROWS, NUM_COLS = len(grid), len(grid[0])

        directions = [
                [0, 1],   # up
                [0, -1],  # down
                [-1, 0],  # left
                [1, 0],   # right
            ]
        
        def perform_bfs(row, col):
            queue = deque([(row, col)])
            visited.add((row, col))
            
            while queue:
                row, col = queue.popleft()

                for row_dir, col_dir in directions:
                    new_row = row + row_dir 
                    new_col = col + col_dir

                    if  (
                        (0 <= new_row < NUM_ROWS) and 
                        (0 <= new_col < NUM_COLS) and 
                        (grid[new_row][new_col] == "1") and 
                        ((new_row, new_col) not in visited)
                    ):
                        queue.append((new_row, new_col))
                        visited.add((new_row, new_col))

        for row in range(NUM_ROWS):
            for col in range(NUM_COLS):

                if grid[row][col] == "1" and (row, col) not in visited:
                    perform_bfs(row, col)
                    num_of_islands += 1

        return num_of_islands
    
            