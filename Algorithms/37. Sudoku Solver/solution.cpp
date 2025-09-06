class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board) { solve(board); }

private:
    bool solve(vector<vector<char>> &board)
    {
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                // If cell is empty
                if (board[row][col] == '.')
                {
                    // Try all digits 1-9
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (isValid(board, row, col, ch))
                        {
                            board[row][col] = ch; // place the digit

                            if (solve(board)) // recurse
                                return true;

                            board[row][col] = '.'; // backtrack
                        }
                    }
                    return false; // If no digit fits, return false
                }
            }
        }
        return true; // All cells filled
    }

    bool isValid(vector<vector<char>> &board, int row, int col, char ch)
    {
        for (int i = 0; i < 9; i++)
        {
            // Check row
            if (board[row][i] == ch)
                return false;

            // Check column
            if (board[i][col] == ch)
                return false;

            // Check 3x3 sub-box
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if (board[boxRow][boxCol] == ch)
                return false;
        }
        return true;
    }
};
