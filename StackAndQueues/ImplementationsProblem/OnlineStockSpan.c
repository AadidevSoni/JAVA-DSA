class StockSpanner {

    List<Integer> lst;

    public StockSpanner() {
        lst = new ArrayList<>();
    }
    
    public int next(int price) {
        lst.add(price);
        int count = 0;
        for(int i=lst.size()-1;i>=0;i--) {
            if(lst.get(i) <= price) {
                count++;
            }else {
                break;
            }
        }
        return count;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */