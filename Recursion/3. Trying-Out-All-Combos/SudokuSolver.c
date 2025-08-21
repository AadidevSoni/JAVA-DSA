public class SudokuSolver {

	public static void main(String[] args) {
		
		char[][] board = {
			    {'.','7','8','.','5','.','3','.','.'},
			    {'.','.','1','9','3','.','.','.','.'},
			    {'.','.','.','2','7','.','.','.','.'},
			    {'.','.','5','.','8','2','.','.','1'},
			    {'.','.','7','.','.','.','.','9','.'},
			    {'.','.','.','.','.','.','.','4','6'},
			    {'6','.','.','.','.','.','1','.','.'},
			    {'.','5','.','.','.','.','.','.','.'},
			    {'7','.','.','3','9','.','.','2','.'}
			};

		boolean res = solve(board);

    if(res) {
      for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
          System.out.println("------+-------+------");
        }
          for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
              System.out.print("| ");
            }
              System.out.print(board[i][j] + " ");
          }
          System.out.println();
        }
	      }else {
	    	  System.out.println("Unsolvable!");
	    }
    }
	
	
	public static boolean solve(char[][] board) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j] == '.') {
                    for(char c='1';c<='9';c++) {
                        if(isValid(board,i,j,c)) {
                            board[i][j] = c;      

                            if(solve(board) == true) {
                                return true;
                            }else {
                                board[i][j] = '.';
                            }                 
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    public static boolean isValid(char[][] board, int row, int col, char c) {
        for(int i=0;i<9;i++) {
            if(board[row][i] == c){
                return false;
            }
            if(board[i][col] == c) {
                return false;
            }
            if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == c) {
                return false;
            }
        }
        return true;
    }

}

