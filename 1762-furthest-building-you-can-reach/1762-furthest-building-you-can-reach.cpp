class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int> pq;
        int i=1;
        for(;i<n;i++) {
            if (heights[i]<= heights[i-1]) continue;
            bricks -= heights[i]-heights[i-1];
            pq.push(heights[i]-heights[i-1]);
            if (bricks<0 && ladders>0) {
                bricks += pq.top();
                pq.pop();
                ladders--;
            } else if (bricks<0 && ladders<=0) break;

            // cout << "index " << i << endl;
            // cout << "ladders " << ladders << endl;
            // cout << "bricks " << bricks << endl;
        }
        return i-1;
    }
};