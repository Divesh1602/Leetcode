class StockSpanner {
public:
    stack<pair<int,int>> s;
    int i=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(s.empty() && i==0)
        {
            s.push({price,0});
            i++;
            return 1;
        }
       int ans;
        while(s.empty()==false && s.top().first<= price)
            s.pop();
        
        ans=(s.empty())? i+1:i-s.top().second;
        s.push({price,i});
        i++;
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */