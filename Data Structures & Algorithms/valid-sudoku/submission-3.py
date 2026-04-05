class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        col_map = {}

        square_map = {}

        row_map = {}

        for row in range(len(board)):
            
            for col in range(len(board[row])):

                if row not in row_map:
                    row_map[row] = []

                if col not in col_map:
                    col_map[col] = []
                
                if (row // 3 , col // 3) not in square_map:
                    square_map[row // 3 , col // 3] = []

                if board[row][col] in row_map[row] and board[row][col] != ".":
                    return False
                elif board[row][col] in col_map[col] and board[row][col] != ".":
                    return False
                elif board[row][col] in square_map[(row // 3 , col // 3)] and board[row][col] != ".":
                    return False
                else:
                    row_map[row].append(board[row][col])
                    col_map[col].append(board[row][col])
                    square_map[(row // 3 , col // 3)].append(board[row][col])
        return True