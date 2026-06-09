class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length;
        List<List<Integer>> revAdj = new ArrayList<>();
        for(int i=0;i<n;i++) {
            revAdj.add(new ArrayList<>());
        }
        int[] indegree = new int[n];
        for(int i=0;i<n;i++) {
            for(int neigh: graph[i]) {
                revAdj.get(neigh).add(i);
                indegree[i]++;
            }
        }
        Queue<Integer> queue = new LinkedList<>();
        List<Integer> safeStates = new ArrayList<>();
        for(int i=0;i<n;i++) {
            if(indegree[i] == 0) {
                queue.add(i); //terminal nodes with no outgoing edges
            }
        }
        while(!queue.isEmpty()) {
            int node = queue.poll();
            safeStates.add(node);
            for(int i=0;i<revAdj.get(node).size();i++) {
                int next = revAdj.get(node).get(i);
                indegree[next]--;
                if(indegree[next] == 0) {
                    queue.add(next);
                }
            }
        }
        Collections.sort(safeStates);
        return safeStates;
    }
} 