class Solution:
    def solve(self, board: List[List[str]]) -> None:
        
        '''
        iterate through every spot on the board, if by only going to Os
        you are able to get to boundary (check using dfs), then it's "safe" other wise it's "unsafe"
        and you should mark it as such        
        '''
        safe = set() # (row, col)

        def perform_dfs(row, col):
            '''
            any cell you are able to visit, add it here 
            '''

            # base case to check if it's in bounds & not already visited
            if not (0 <= row < NROWS) or not (0 <= col < NCOLS): return
            if board[row][col] == 'X': return
            if (row, col) in safe: return

            safe.add((row, col))

            perform_dfs(row + 1, col)
            perform_dfs(row - 1, col)
            perform_dfs(row, col - 1)
            perform_dfs(row, col + 1)


        NROWS, NCOLS = len(board), len(board[0])

        for row in range(NROWS):
            for col in range(NCOLS):
                if (row == 0 or row == NROWS - 1) or (col == 0 or col == NCOLS - 1):
                    perform_dfs(row, col)


        for r in range(NROWS):
            for c in range(NCOLS):
                if board[r][c] == 'O' and (r, c) not in safe:
                    board[r][c] ='X'

