class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int, std::unordered_set<char>> row_map; // row, int
        std::unordered_map<int, std::unordered_set<char>> col_map; // col, int 
        std::map<std::pair<int, int>, std::unordered_set<char>> square_map; // <row, col>, int
        int BOARD_SIZE = board.size();
        int ROW_SIZE = board[0].size();

        for (int row = 0; row < BOARD_SIZE; row++){
            for (int col = 0; col < ROW_SIZE; col++){
                
                char curr_num = board[row][col];

                if (curr_num == '.') continue;

                if (row_map[row].count(curr_num) || 
                    col_map[col].count(curr_num) || 
                    square_map[{row / 3, col / 3}].count(curr_num)){
                    return false;
                }
                row_map[row].insert(curr_num);
                col_map[col].insert(curr_num);
                square_map[{row / 3, col / 3}].insert(curr_num);
            }
        }

        return true;


    }
};
