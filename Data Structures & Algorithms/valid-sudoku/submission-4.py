class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row_seen = {}
        col_seen = {}
        square_seen = {}
        for row in range(len(board)):
            for col in range(len(board[row])):
                if board[row][col] == '.':
                    continue
                number = board[row][col]
                row_quad = self.normalize_section(row)
                col_quad = self.normalize_section(col)

                # initialize arrays for row & col & square
                if row not in row_seen.keys():
                    row_seen[row] = []
                if col not in col_seen.keys():
                    col_seen[col] = []
                if (row_quad, col_quad) not in square_seen.keys():
                    square_seen[(row_quad, col_quad)] = []

                if number in row_seen[row]:
                    return False
                if number in col_seen[col]:
                    print('second')
                    return False
                if number in square_seen[(row_quad, col_quad)]:
                    print('third')
                    return False
                else:
                    row_seen[row].append(number)
                    col_seen[col].append(number)
                    square_seen[(row_quad, col_quad)].append(number)
        return True
    
    def normalize_section(self, section):
        section = int(section)
        if section <= 2:
            return 0
        elif section <= 5:
            return 1
        else:
            return 2