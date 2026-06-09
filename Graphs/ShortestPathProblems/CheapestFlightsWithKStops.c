class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        List<List<Pair>> adjL = new ArrayList<>();
        for(int i=0;i<n;i++) {
            adjL.add(new ArrayList<>());
        }
        int m = flights.length;
        for(int i=0;i<m;i++) {
            adjL.get(flights[i][0]).add(new Pair(flights[i][1],flights[i][2]));
        }
        int[] dist = new int[n];
        for(int i=0;i<n;i++) {
            dist[i] = Integer.MAX_VALUE;
        }
        dist[src] = 0;
        Queue<Tuple> queue = new LinkedList<>();
        queue.offer(new Tuple(0,src,0));

        while(!queue.isEmpty()) {
            Tuple city = queue.poll();
            int stops = city.stops;
            int node = city.src;
            int cost = city.dist;
            if(stops > k) continue;
            for(int i=0;i<adjL.get(node).size();i++) {
                Pair adj = adjL.get(node).get(i);
                int adjNode = adj.to;
                int adjDist = adj.price;
                if(cost + adjDist < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost + adjDist;
                    queue.add(new Tuple(stops+1,adjNode,cost+adjDist));
                }
            }
        }

        if(dist[dst] == Integer.MAX_VALUE) {
            return -1;
        }
        return dist[dst];
    }
}

class Pair {
    int to;
    int price;
    public Pair(int to, int price) {
        this.to = to;
        this.price = price;
    }
}

class Tuple {
    int stops;
    int src;
    int dist;
    public Tuple(int stops, int src, int dist) {
        this.stops = stops;
        this.src = src;
        this.dist = dist;
    }
}