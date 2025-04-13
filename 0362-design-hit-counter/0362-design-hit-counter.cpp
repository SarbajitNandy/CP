class HitCounter {
public:
    queue<int> orders;
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        orders.push(timestamp);
    }
    
    int getHits(int timestamp) {
        while(!orders.empty()) {
            if (timestamp - orders.front() >= 300) {
                orders.pop();
            } else break;
        }

        return orders.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */