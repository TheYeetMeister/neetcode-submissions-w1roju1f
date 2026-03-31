class StockSpanner {
    stack<pair<int, int>> buf;
public:
    StockSpanner() {}
    
    int next(int price) {
        int count = 1;

        while (!buf.empty() && buf.top().first <= price) {
            count += buf.top().second;
            buf.pop();
        }

        buf.push({price, count});
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */