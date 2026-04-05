class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        outer_left, outer_right = 0, len(matrix) - 1

        while outer_left <= outer_right:

            inner_middle = (outer_left + outer_right) // 2
            inner_array = matrix[inner_middle]
            left, right = 0, len(inner_array) - 1

            while left <= right:

                middle = (left + right) // 2

                if inner_array[middle] == target:
                    return True
                elif inner_array[middle] > target:
                    right = middle - 1
                else:
                    left = middle + 1
            
            if target > max(inner_array):
                outer_left = inner_middle + 1
            else:
                outer_right = inner_middle - 1
        
        return False