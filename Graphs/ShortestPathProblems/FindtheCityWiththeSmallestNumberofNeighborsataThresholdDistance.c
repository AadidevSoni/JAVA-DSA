class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {

        List<List<Pair>> adj = new ArrayList<>();
        for(int i=0;i<n;i++) {
            adj.add(new ArrayList<>());
        }

        for(int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj.get(u).add(new Pair(v, wt));
            adj.get(v).add(new Pair(u, wt));
        }

        int minReachable = Integer.MAX_VALUE;
        int city = -1;

        for(int src = 0; src < n; src++) {
            int[] dist = new int[n];
            Arrays.fill(dist, Integer.MAX_VALUE);
            PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> a.weight - b.weight);
            dist[src] = 0;
            pq.offer(new Pair(src, 0));
            while(!pq.isEmpty()) {
                Pair curr = pq.poll();
                int node = curr.node;
                int weight = curr.weight;
                if(weight > dist[node]) continue;
                for(Pair next : adj.get(node)) {
                    int adjNode = next.node;
                    int adjWeight = next.weight;
                    if(weight + adjWeight < dist[adjNode]) {
                        dist[adjNode] = weight + adjWeight;
                        pq.offer(new Pair(adjNode, dist[adjNode]));
                    }
                }
            }

            int count = 0;
            for(int i = 0; i < n; i++) {
                if(dist[i] <= distanceThreshold) {
                    count++;
                }
            }

            // Tie -> larger city index wins
            if(count <= minReachable) {
                minReachable = count;
                city = src;
            }
        }

        return city;
    }
}

class Pair {
    int node;
    int weight;

    Pair(int node, int weight) {
        this.node = node;
        this.weight = weight;
    }
}