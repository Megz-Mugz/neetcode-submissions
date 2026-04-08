class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const char BLANK = '.';
        std::map<int, std::set<char>> row_map; // row -> ['1', '2'] set
        std::map<int, std::set<char>> col_map; // col -> ['1', '2'] set
        std::map<std::pair<int, int>, std::set<char>> square_map;

        for (int row = 0; row < board.size(); row++){
            for (int col = 0; col < board[row].size(); col++){
                auto current_num = board[row][col];
                if (current_num == BLANK) continue;

                auto square_index = convert_to_square_coor(row, col);
                
                std::cout << "Current num: " << current_num << " located in: (" << square_index.first << ", " << square_index.second << ")" << std::endl;

                if (row_map[row].contains(current_num) ||
                    col_map[col].contains(current_num) ||
                    square_map[square_index].contains(current_num)
                ){
                    return false;
                }

                row_map[row].insert(current_num);
                col_map[col].insert(current_num);
                square_map[square_index].insert(current_num);
                
            }
        }

        return true;
    }

private:
    int convert_to_coordinate(int grind_index) const {
        
        if (grind_index < 3) {
            return 0;
        } else if (grind_index < 6){
            return 1;
        } else {
            return 2;
        }
        return -1;
    }

    std::pair<int, int> convert_to_square_coor(const int row, const int col) const {
        return std::make_pair(convert_to_coordinate(row), convert_to_coordinate(col));
    }
};
