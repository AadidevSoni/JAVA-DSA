//BFS
//Use BFS and not DFS when you have to find minimum path or optimal as DFS go through all paths and can also return bigger path.

class Solution {
    public int minJumps(int[] arr) {
        int n = arr.length;
        if(n == 1) {
            return 0;
        }
        HashMap<Integer, List<Integer>> map = new HashMap<>();
        
        for(int i=0;i<n;i++) {
            map.computeIfAbsent(arr[i], k -> new ArrayList<>()).add(i);
        }

        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[n];

        q.offer(0);
        visited[0] = true;
        int jumps = 0;

        while(!q.isEmpty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                int curr = q.poll();
                if(curr == n-1) {
                    return jumps;
                }

                if(curr+1 < n && !visited[curr+1]) {
                    visited[curr+1] = true;
                    q.offer(curr+1);
                }

                if(curr-1 >= 0 && !visited[curr-1]) {
                    visited[curr-1] = true;
                    q.offer(curr-1);
                }

                if(map.containsKey(arr[curr])) {
                    for(int nxt: map.get(arr[curr])) {
                        if(!visited[nxt]) {
                            visited[nxt] = true;
                            q.offer(nxt);
                        }
                    }
                    map.remove(arr[curr]);
                }
            }
            jumps++;
        }
        return jumps;
    }
}