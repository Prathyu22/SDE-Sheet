//https://leetcode.com/problems/n-queens/description/

/*N Queen Problem | Return all Distinct Solutions to the N-Queens Puzzle
Problem Statement: The n-queens is the problem of placing n queens on n × n chessboard such that no two queens can attack each other. Given an integer n, return all distinct solutions to the n -queens puzzle. Each solution contains a distinct boards configuration of the queen’s placement, where ‘Q’ and ‘.’ indicate queen and empty space respectively.

Examples:

Input: n = 4

Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]

Explanation: There exist two distinct solutions to the 4-queens puzzle as shown below

Arrangement 1
..Q.
Q…
…Q
.Q..

Arrangement 2
.Q..
…Q
Q…
..Q.
*/

class Solution {

public:
    void solve(int col, vector<vector<string>>& ans, vector<string>& board, vector<int>& leftRow, vector<int>& leftDia, vector<int>& rightDia, int ind)
    {
        if(col == ind)
        {
            ans.push_back(board);
            return;
        }

        for(int row=0; row<ind; row++)
        {
            if(leftRow[row] == 0 && leftDia[row+col] == 0 && rightDia[(ind-1)+col-row] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                leftDia[row+col] = 1;
                rightDia[ind-1+col-row] = 1;

                solve(col+1, ans, board, leftRow, leftDia, rightDia, ind);

                board[row][col] = '.';
                leftRow[row] = 0;
                leftDia[row+col] = 0;
                rightDia[ind-1+col-row] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        // ----------- Optimized code (HASHING). ----------------
        // ----------- TC = O(N! * N) and SC = O(N) -----------
         vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for(int i=0; i<n; i++)
        {
            board[i] = s;
        }
        vector<int> leftRow(n, 0), leftDia(2*n-1, 0), rightDia(2*n-1, 0);

        solve(0, ans, board, leftRow, leftDia, rightDia, n);
        return ans;
    }


/*bool isSafe(int row, int col, vector<string>& board, int ind)
{
    //checking upper diagonol
    int duprow = row;
    int dupcol = col;

    while(row>=0 && col>=0) 
    {
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    } 

    row = duprow;
    col = dupcol;
    while(col>=0){
        if(board[row][col] == 'Q') return false;
        col--;
    }

    row = duprow;
    col = dupcol;
    while(row<ind && col>=0)
    {
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }

    return true;
}

public:
    void solve(int col, vector<string> &board, vector<vector<string>>& ans, int ind)
    {
        if(col == ind)
        {
            ans.push_back(board);
            return;
        }

        for(int row=0; row<ind; row++)
        {
            if(isSafe(row, col, board, ind))
            {
                board[row][col] = 'Q';
                solve(col+1, board, ans, ind);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        //--------- 1st Method ------------ 

        // ----------- TC = O(N! * N) and SC = O(N^2) -----------
        
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for(int i=0; i<n; i++)
        {
            board[i] = s; // This assigns a string of size 'n' to each index of the board. (that means each row of the board is assigned with a string of size 'n'.)
        }

        solve(0, board, ans, n);
        return ans;
    }*/
};