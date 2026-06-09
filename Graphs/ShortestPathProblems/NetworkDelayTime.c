class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<Pair>> adjL = new ArrayList<>();
        for(int i=0;i<=n;i++) {
            adjL.add(new ArrayList<>());
        }
        for(int i=0;i<times.length;i++) {
            adjL.get(times[i][0]).add(new Pair(times[i][1],times[i][2]));
        }
        int[] dist = new int[n+1];
        Arrays.fill(dist,Integer.MAX_VALUE);
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> a.weight - b.weight);
        dist[k] = 0;
        pq.offer(new Pair(k,0));

        while(!pq.isEmpty()) {
            Pair curr = pq.poll();
            int node = curr.node;
            int time = curr.weight;
            if(time > dist[node]) continue;
            for(int i=0;i<adjL.get(node).size();i++) {
                Pair adjNode = adjL.get(node).get(i);
                int nextNode = adjNode.node;
                int nextTime = adjNode.weight;
                if(time + nextTime < dist[nextNode]) {
                    dist[nextNode] = time + nextTime;
                    pq.offer(new Pair(nextNode,dist[nextNode]));
                }
            }
        }

        int ans = 0;
        for(int i=1;i<=n;i++) {
            if(dist[i] == Integer.MAX_VALUE) {
                return -1;
            }
            ans = Math.max(ans,dist[i]);
        }

        return ans;

    }
}

class Pair {
    int node;
    int weight;
    public Pair(int node, int weight) {
        this.node = node;
        this.weight = weight;
    }
}