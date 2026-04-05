class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        
        EMPTY, FRESH_FRUIT, ROTTEN_FRUIT = 0, 1, 2
        NROWS, NCOLS = len(grid), len(grid[0])
        directions = [(0, 1), (0, -1), (-1, 0), (1, 0)] # up, down, left, right
        minutes = 0

        # find all the coordinates of rotten fruit
        # append all of those to the queue
        # keep going until the queue is empty
        queue = deque()
        fresh_count = 0
        for row in range(NROWS):
            for col in range(NCOLS):
                if (grid[row][col] == ROTTEN_FRUIT):
                    queue.append((row, col))
                elif (grid[row][col] == FRESH_FRUIT):
                    fresh_count += 1

        # odd edge case, if there are no fresh fruits, just return
        if fresh_count == 0: return minutes

        while queue:
            changed = False
            len_of_level = len(queue)
            for _ in range(len_of_level):
                
                row, col = queue.popleft()
                
                for rd, cd in directions:
                    nr, nc = row + rd, col + cd
                    
                    if (0 <= nr < NROWS) and (0 <= nc < NCOLS) and (grid[nr][nc] == FRESH_FRUIT):
                        grid[nr][nc] = ROTTEN_FRUIT
                        fresh_count -= 1
                        queue.append((nr, nc))
                        changed = True # going into this condition implies there was a fresh to rotten conversion, and you must TAKE MORE TIME to explore it

            if changed: minutes += 1
        
        return minutes if fresh_count == 0 else -1
