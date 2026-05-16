class Solution {
    public int lastRemaining(int n) {
        List<Integer> arr = new ArrayList<>();
        for(int i=1;i<=n;i++) {
            arr.add(i);
        }
        getLast(arr,0);
        return arr.get(0);
    }

    public void getLast(List<Integer> arr,int dir) {
        if(arr.size() == 1) {
            return;
        }

        List<Integer> next = new ArrayList<>();

        if(dir == 0) {
            for(int i=1;i<arr.size();i+=2) {
                next.add(arr.get(i));
            }
            getLast(next,1);
        }
        if(dir == 1) {
            for(int i=arr.size()-2;i>=0;i-=2) {
                next.add(arr.get(i));
            }
            Collections.reverse(next);
            getLast(next,0);
        }
        arr.clear();
        arr.addAll(next);   
    }
}