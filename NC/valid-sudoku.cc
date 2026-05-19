class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check cols
        for (int xi{0}; xi<9; xi++) {
            std::array<bool, 9> xs{};
            for (int yi{0}; yi<9; ++yi) {
                if (board[yi][xi] == '.') {
                    continue;
                }
                int digit=board[yi][xi]-'1'; // zero-indexed
                if (xs[digit]) {
                    return false;
                }
                xs[digit]=true;
            }
        }

        // check rows
        for (int yi{0}; yi<9; yi++) {
            std::array<bool, 9> xs{};
            for (int xi{0}; xi<9; ++xi) {
                if (board[yi][xi] == '.') {
                    continue;
                }
                int digit=board[yi][xi]-'1'; // zero-indexed
                if (xs[digit]) {
                    return false;
                }
                xs[digit]=true;
            }
        }

        for (int yi{0}; yi<3; ++yi) {
            for (int xi{0}; xi<3; ++xi) {
                std::array<char, 9> xs{}; // i am lazy
                xs[0] = board[yi*3][xi*3];
                xs[1] = board[yi*3][xi*3+1];
                xs[2] = board[yi*3][xi*3+2];
                xs[3] = board[yi*3+1][xi*3];
                xs[4] = board[yi*3+1][xi*3+1];
                xs[5] = board[yi*3+1][xi*3+2];
                xs[6] = board[yi*3+2][xi*3];
                xs[7] = board[yi*3+2][xi*3+1];
                xs[8] = board[yi*3+2][xi*3+2];
                std::array<bool, 9> ys{};
                for (int i{0}; i<9; ++i) {
                    if (xs[i] == '.') {
                        continue;
                    }
                    int digit=xs[i]-'1';
                    if (ys[digit]) {
                        return false;
                    }
                    ys[digit]=true;
                }
            }
        }
        return true;
    }
};
