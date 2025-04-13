class HitCounter {
public:
    vector<int> orders;
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        orders.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        int low = timestamp - 300;
        int high = timestamp;

        int id = upper_bound(orders.begin(), orders.end(), low) - orders.begin();

        return orders.size() - id;

    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */