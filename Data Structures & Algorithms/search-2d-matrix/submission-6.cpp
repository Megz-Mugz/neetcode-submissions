class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int ROWS = matrix.size();
        const int COLS = matrix[0].size();

        int left_row_idx = 0;
        int right_row_idx = ROWS - 1;

        while (left_row_idx <= right_row_idx){
            int middle_row_idx = left_row_idx + (right_row_idx - left_row_idx) / 2;

            std::cout << "Middle row index is: " << middle_row_idx << std::endl;

            auto middle_row = matrix[middle_row_idx];

            if (middle_row[0] > target){
                right_row_idx = middle_row_idx - 1;
                continue;
            } else if (middle_row[COLS - 1] < target){
                left_row_idx = middle_row_idx + 1;
                continue;
            } else {
                std::cout << target << " might be in row: " << middle_row_idx << std::endl;
                int left = 0;
                int right = COLS - 1;
                while (left <= right){
                    int middle = left + (right - left) / 2;

                    if (middle_row[middle] == target){
                        return true;
                    } else if (middle_row[middle] > target){
                        right = middle - 1;
                    } else {
                        left = middle + 1;
                    }
                }
                break;
            }
        }
        return false;
    }
};