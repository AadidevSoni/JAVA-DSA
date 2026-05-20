class Solution {
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;
        int[] visited = new int[n];
        boolean res = f(start,arr,n,visited);
        return res;
    }

    public static boolean f(int start, int[] arr, int n, int[] visited) {
        if(start >= n || start < 0 || visited[start] == 1) {
            return false;
        }
        if(arr[start] == 0) {
            return true;
        }
        visited[start] = 1;
        boolean j1 = f(start+arr[start],arr,n,visited);
        boolean j2 = f(start-arr[start],arr,n,visited);
        return j1 || j2;
    }
}