class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int left = 0, right = matrix.size() - 1;
        int middle;
        std::vector<int> inner_matrix;
        int inner_left, inner_right;
        int inner_middle;

        while (left <= right){
            middle = std::floor((left + right) / 2);

            inner_matrix = matrix[middle];

            inner_left = 0;
            inner_right = inner_matrix.size() - 1;

            while (inner_left <= inner_right){
                inner_middle = std::floor((inner_left + inner_right) / 2);

                if (inner_matrix[inner_middle] == target){
                    return true;
                } else if (inner_matrix[inner_middle] > target){
                    inner_right = inner_middle - 1;
                } else {
                    inner_left = inner_middle + 1;
                }
            }

            if (target > inner_matrix[inner_matrix.size() - 1]){
                left = middle + 1;
            } else if (target < inner_matrix[0]){
                right = middle - 1;
            } else {
                return false;
            }
        }
        return false;
    }
};
