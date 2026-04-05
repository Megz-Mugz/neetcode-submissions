class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        LAND = 2147483647
        TREASURE = 0
        WATER = -1
        
        NROWS, NCOLS = len(grid), len(grid[0])

        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]

        def perform_bfs(row, col):

            queue = deque([(row, col)])
            distance = 1

            while queue:
                length_of_level = len(queue)
                for _ in range(length_of_level):
                    row, col = queue.popleft()

                    for row_dir, col_dir in directions:

                        new_row = row + row_dir
                        new_col = col + col_dir

                        if (0 <= new_row < NROWS) and (0 <= new_col < NCOLS) and (grid[new_row][new_col] != WATER):
                            
                                if distance < grid[new_row][new_col]:
                                    grid[new_row][new_col] = distance
                                    queue.append((new_row, new_col))

                distance += 1

        
        for row in range(NROWS):
            for col in range(NCOLS):
                if grid[row][col] == TREASURE:
                    perform_bfs(row, col)