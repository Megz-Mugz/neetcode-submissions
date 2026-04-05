class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        NROWS, NCOLS = len(grid), len(grid[0])

        visited = set()

        direction = [
            [0, 1],   # up
            [0, -1],  # down
            [1, 0],   # right
            [-1, 0]   # left
        ]
        
        max_area_of_island = 0

        def perform_bfs(row, col):
            visited_now = 0
            
            queue = deque([(row, col)])
            visited.add((row, col))
            visited_now += 1

            while queue:
                row, col = queue.popleft()
                for row_dir, col_dir in direction:
                    new_row = row + row_dir
                    new_col = col + col_dir
                    print(f'row: {new_row} col: {new_col}')
                    if (
                        (0 <= new_row < NROWS) and
                        (0 <= new_col < NCOLS) and 
                        (grid[new_row][new_col] == 1) and 
                        ((new_row, new_col) not in visited)
                    ):
                        visited.add((new_row, new_col))
                        visited_now += 1
                        queue.append((new_row, new_col))
            print(visited_now)
            return visited_now



        for row in range(NROWS):
            for col in range(NCOLS):
                square = grid[row][col]
                if square == 1 and (row, col) not in visited: # if it's land
                    print(f'row: {row} col: {col}')
                    max_area_of_island = max(perform_bfs(row, col), max_area_of_island)

        return max_area_of_island
