class Solution {
    public int countPaths(int n, int[][] roads) {
        List<List<Pair>> adjL = new ArrayList<>();
        for(int i=0;i<n;i++) {
            adjL.add(new ArrayList<>());
        }
        for(int i=0;i<roads.length;i++) {
            adjL.get(roads[i][0]).add(new Pair(roads[i][1],roads[i][2]));
            adjL.get(roads[i][1]).add(new Pair(roads[i][0],roads[i][2]));
        }
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> Long.compare(a.weight, b.weight));
        long[] ways = new long[n];
        long[] dist = new long[n];
        Arrays.fill(dist,Long.MAX_VALUE);
        dist[0] = 0;
        ways[0] = 1;
        pq.offer(new Pair(0,0)); //node,time
        while(!pq.isEmpty()) {
            Pair curr = pq.poll();
            int node = curr.node;
            long time = curr.weight;
            if(time > dist[node])continue;
            for(int i=0;i<adjL.get(node).size();i++) {
                Pair adjNode = adjL.get(node).get(i);
                int next = adjNode.node;
                long nextTime = adjNode.weight;
                if(time + nextTime < dist[next]) {
                    dist[next] = time + nextTime;
                    ways[next] = ways[node];
                    pq.offer(new Pair(next,dist[next]));
                }else if(time + nextTime == dist[next]) {
                    ways[next] = (ways[next] + ways[node]) % 1000000007;
                }
            }
        }
        return (int)ways[n-1] % 1000000007;
    }
}

class Pair {
    int node;
    long weight;
    public Pair(int node, long weight) {
        this.node = node;
        this.weight = weight;
    }
}