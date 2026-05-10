class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const char BLANK = '.';
        const int NUM_ROWS = board.size();
        const int NUM_COLS = board[0].size();
        std::map<int, std::set<char>> row_map; // row -> ['1', '2'] set
        std::map<int, std::set<char>> col_map; // col -> ['1', '2'] set
        std::map<std::pair<int, int>, std::set<char>> square_map; // (squre_row, square_y) -> ['1', '2'] set


        for (int row = 0; row < NUM_ROWS; row++){
            for (int col = 0; col < NUM_COLS; col++){
                
                auto current_num = board[row][col];
                
                // do nothing on a '.'
                if (current_num == BLANK) continue;

                auto square_index = convert_to_square_coor(row, col);
                
                // kept for logging purposes
                std::cout << "Current num: " << current_num << " located in: (" << square_index.first << ", " << square_index.second << ")" << std::endl;

                // check to see if the current num has already been seen on the current row, col, or square
                if (row_map[row].contains(current_num) ||
                    col_map[col].contains(current_num) ||
                    square_map[square_index].contains(current_num)
                ){
                    return false;
                }

                // insert the current_num into all 3 potential locations
                row_map[row].insert(current_num);
                col_map[col].insert(current_num);
                square_map[square_index].insert(current_num);
                
            }
        }

        return true;
    }

private:
    // scales an index on the grid to a 3x3 game board
    int convert_to_coordinate(const int& grind_index) const {
        
        if (grind_index < 3) {
            return 0;
        } else if (grind_index < 6){
            return 1;
        } else {
            return 2;
        }
        return -1;
    }

    // returns a pair of the new x and y for the square grid
    std::pair<int, int> convert_to_square_coor(const int& row, const int& col) const {
        return std::make_pair(convert_to_coordinate(row), convert_to_coordinate(col));
    }
};
