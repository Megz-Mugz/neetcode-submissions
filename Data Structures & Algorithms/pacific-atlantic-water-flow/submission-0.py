class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        
        # 1. start with EITHER row = 0 or col = 0, and 
        # 2. using the rule (only travel w/ heights <= curr height)
        # 3. end up at EITHER row = len(heights) - 1 or col = len(heights[0])
        # use a recursive dfs approach
        NROWS, NCOLS = len(heights), len(heights[0])

        def dfs(row, col, visited, prev, reached):

            # validate input 
            if (not (0 <= row < NROWS) or 
                not (0 <= col < NCOLS) or
                (heights[row][col]) > heights[prev[0]][prev[1]] or
                (row, col) in visited
                ): return
            
            visited.add((row, col))
            
            # at a border coordinate for the pacific
            if (row == 0 or col == 0):
                reached["pacific"] = True
            
            # at a border coordinate for the atlantic
            if (row == NROWS - 1 or col == NCOLS - 1):
                reached["atlantic"] = True
            
            
            dfs(row=row - 1, col=col, visited=visited, prev=(row, col), reached=reached) # check up
            dfs(row=row + 1, col=col, visited=visited, prev=(row, col), reached=reached) # check down
            dfs(row=row, col=col - 1, visited=visited, prev=(row, col), reached=reached) # check left
            dfs(row=row, col=col + 1, visited=visited, prev=(row, col), reached=reached) # check right

        output = []
        for row in range(NROWS):
            for col in range(NCOLS):
                reached = {"pacific": False, "atlantic": False}
                
                dfs(row=row, col=col, visited=set(), prev=(row, col), reached=reached)
                
                if reached["pacific"] and reached["atlantic"]: output.append([row, col])
        
        return output



                