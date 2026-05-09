class Pair{
public:
int value;
int span;
};

class StockSpanner {
public:
     stack<Pair>s;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int cspan=1;
        while(!s.empty() && s.top().value<=price){
            cspan+=s.top().span;
            s.pop();
        }
        s.push({price,cspan});
        return cspan;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */