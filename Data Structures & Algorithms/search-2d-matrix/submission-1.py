class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        outer_left = 0
        outer_right = len(matrix) - 1

        less_than_flag = False
        greater_than_flag = False


        while outer_left <= outer_right:
            outer_mid = (outer_left + outer_right) // 2 

            inner_left = 0
            inner_right = len(matrix[outer_mid]) - 1

            while inner_left <= inner_right:

                inner_mid = (inner_left + inner_right) // 2

                print(matrix[outer_mid][inner_mid])

                if matrix[outer_mid][inner_mid] > target:
                    inner_right = inner_mid - 1
                    less_than_flag = True
                elif matrix[outer_mid][inner_mid] < target:
                    inner_left = inner_mid + 1
                    greater_than_flag = True
                else:
                    return True
            if greater_than_flag:
                outer_left = outer_mid + 1
            if less_than_flag:
                outer_right = outer_mid - 1
        return False
            


