import java.util.*;

class Solution {

    public boolean canFinish(int numCourses, int[][] prereq) {

      List<List<Integer>> mygraph = new ArrayList<>();

      for (int i=0; i< numCourses; i++) {
        mygraph.add(new ArrayList<>());
      }

      for (int[] pre: prereq) {
        mygraph.get(pre[1]).add(pre[0]);
      }

       int[] vis = new int[numCourses]; 

      for (int i = 0; i < numCourses; i++) {
        if (vis[i] == 0) {
          if (dfs(i, mygraph, vis)) {
            return false; 
          }
        }
      }
      return true;
    }

    private boolean dfs(int node, List<List<Integer>> mygraph,int[] vis) {
      vis[node] = 1; 

      for (int neighbor : mygraph.get(node)) {
        if (vis[neighbor] == 1) return true; 
        if (vis[neighbor] == 0 && dfs(neighbor, mygraph, vis)) {
          return true;
        }
      }

      vis[node] = 2; 
      return false;
    }
}
