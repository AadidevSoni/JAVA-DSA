public class WordSearch {

	public static void main(String[] args) {
		
		char board[][] = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
		String word = "ABCCEDASF";
		
		int m = board.length;
		int n = board[0].length;
		int c = 0;
		
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				if(backtrack(0,board,word,i,j)) {
					System.out.println("Word Found");
					c++;
				}
			}
		}
		
		if(c == 0) {
			System.out.println("Word Not Found");
		}
	}
	
	public static boolean backtrack(int ind, char[][] board, String word, int row, int col) {
		if(ind == word.length()) {
			return true;
		}
		
		// Out of bounds or mismatch
		if(row<0 || row>=board.length || col<0 || col>board[0].length || board[row][col] != word.charAt(ind)) {
			return false;
		}
		
		// Mark the cell as visited
		char temp = board[row][col];
		board[row][col] = '#';
		
		// Explore 4 directions
		boolean found = backtrack(ind+1,board,word,row+1,col) ||
						backtrack(ind+1,board,word,row-1,col) ||
						backtrack(ind+1,board,word,row,col+1) ||
						backtrack(ind+1,board,word,row,col-1);
		
		// Restore the cell
		board[row][col] = temp;
		
		return found;
	}

}
