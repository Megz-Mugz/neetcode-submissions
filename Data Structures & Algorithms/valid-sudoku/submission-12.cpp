class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<size_t, std::set<char>> row_map; // row -> nums
        std::unordered_map<size_t, std::set<char>> col_map; // col -> nums
        std::map<std::pair<size_t, size_t>, std::set<char>> square_map; // (x, y) -> nums

        for (int row = 0; row < board.size(); row++){
            for (int col = 0; col < board[row].size(); col++){
                
                if (board[row][col] == '.') continue;
                
                auto digit = board[row][col];
                
                // convert to a valid square coordinate
                auto [row_coor, col_coor] = convertToSquareCoordinates(row, col);

                if (
                    row_map[row].contains(digit) ||
                    col_map[col].contains(digit) ||
                    square_map[std::make_pair(row_coor, col_coor)].contains(digit)
                ) {
                    return false;
                }

                row_map[row].insert(digit);
                col_map[col].insert(digit);
                square_map[std::make_pair(row_coor, col_coor)].insert(digit);
            }
        }

        return true;
    }
private:
    std::pair<size_t, size_t> convertToSquareCoordinates(size_t row, size_t col){
        size_t row_coordinate{};
        size_t col_coordinate{};

        if (row < 3){
            row_coordinate = 0;
        } else if (row < 6){
            row_coordinate = 1;
        } else {
            row_coordinate = 2;
        }

        if (col < 3){
            col_coordinate = 0;
        } else if (col < 6){
            col_coordinate = 1;
        } else {
            col_coordinate = 2;
        }

        return std::make_pair(row_coordinate, col_coordinate);
    }
};
