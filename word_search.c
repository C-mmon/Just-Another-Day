
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

For example, given the following board:

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
exists(board, "ABCCED") returns true, exists(board, "SEE") returns true, exists(board, "ABCB") returns false.

//BackTracking 
Backtracking is basically brute force where we check all solution 
The most important parts of backtracking using recursive function are:
(1) return when we reach to the end and no more states can be generated.
(2) restore the state after calling the recursive function.

Pseudo Algorithm for backtracking 
def backtrack(state):
(1) if there are no more states that can be generated from the current state, return. //Base condition

For loop
    (2) change the current state to its neighboring state
    (3) backtrack(state)
    (4) restore the state (backtrack)


//Coming to the problem 
For each cell, traverse the entire matrix.
Check if matrix[i][j] == word[index]. (we are using the index to keep track of the characters that we have already checked in the word during backtracking.)
If it is true, then check to repeat the same process for the adjacent cells and for the next index in the word.
If it is false, then return to the previous state where we received a true value and then further check any remaining and unvisited cells.

for the four possible directions (up, down, left, right):

1) Down (i+1,j)th in matrix
2) Right(i,j+1)th in matrix
3) Up (i-1,j)th in matrix
4) Left(i,j-1)th in matrix

(i) Check if matrix[i][j] == word[index].(inside the grid)
Note: (we are using the index to keep track of the characters that we have already checked in the word during backtracking.)

    if True: 
       Repeat the same process for the adjacent cell and for the next index in the word
    else:
      return to previous state where we received true value and further check any remaining and unvisited cells.

    bool exist(vector<vector<char>>& board, string word) {
        //Size of row
        int row= board.size();
        int col = board[0].size();
        for(int i = 0 ; i < row ; ++i)
           for(int j = 0 ; j < col ; ++j)
               if(search(0 , i , j , board , word))
                   return true;
       return false;
    }
    bool search(int StringIndex, int x_cord, int y_cord, vector<vector<char>> & board, string word)
    {
        if(StringIndex == word.size())
        {
            return true;
        }

        //boundary condition check 
        if(x_cord <0 || y_cord < 0 ||  x_cord >= board.size() || y_cord >= board[0].size())
        {
            return false;
        }
        if(board[x_cord][y_cord] != word[StringIndex])
        {
            return false;
        }
        // we are using the existing board to mark visited and unvisted character
        // but rememeber for back tracking we need to restore the state back 

        char temp = board[x_cord][y_cord];

        //mark visted
        board[x_cord][y_cord]='.';
               if(search(StringIndex + 1 , x_cord - 1 , y_cord , board , word) || search(StringIndex + 1 , x_cord + 1 , y_cord , board , word) || search(StringIndex + 1 , x_cord , y_cord - 1 , board , word) || search(StringIndex + 1 , x_cord , y_cord + 1 , board , word))
               {
                return true;
               }
               //remember we will enter here only if solution is not possible 

               board[x_cord][y_cord]= temp;
               return false;
    }