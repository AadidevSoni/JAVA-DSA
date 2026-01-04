class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int r = image.length;
        int c = image[0].length;

        Queue<Pair> queue = new LinkedList<>();
        queue.add(new Pair(sr,sc));
        int initialColor = image[sr][sc];
        if (initialColor == color) return image;
        image[sr][sc] = color;
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!queue.isEmpty()) {
            int _row = queue.peek().row;
            int _col = queue.peek().col;
            queue.remove();
            for(int i=0;i<4;i++) {
                int nrow = _row + drow[i];
                int ncol = _col + dcol[i];
                if(nrow >= 0 && nrow < r && ncol >= 0 && ncol < c && image[nrow][ncol] == initialColor) {
                    image[nrow][ncol] = color;
                    queue.add(new Pair(nrow,ncol));
                }
            }
        }

        return image;
    }

    class Pair {
        int row;
        int col;
        Pair(int _row, int _col) {
            row = _row;
            col = _col;
        }
    }
}