class Solution {
public:
    bool solve(int row, int col, vector<vector<char>>& board,
               string& word, int index) {

        // All characters of the word are matched
        if(index == word.size()) {
            return true;
        }

        // Check boundaries
        if(row < 0 || col < 0 ||
           row >= board.size() || col >= board[0].size()) {
            return false;
        }

        // Character does not match
        if(board[row][col] != word[index]) {
            return false;
        }

        // Store the current character
        char ch = board[row][col];

        // Mark this cell as visited
        board[row][col] = '#';

        // Explore all four directions
        bool found = solve(row - 1, col, board, word, index + 1) ||
                     solve(row + 1, col, board, word, index + 1) ||
                     solve(row, col - 1, board, word, index + 1) ||
                     solve(row, col + 1, board, word, index + 1);

        // Backtrack: restore the original character
        board[row][col] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(board[i][j] == word[0]) {
                    if(solve(i, j, board, word, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};