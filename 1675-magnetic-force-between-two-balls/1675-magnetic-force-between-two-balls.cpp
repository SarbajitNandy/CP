class Solution {
public:

    int maxDistance(vector<int>& position, int m) {
        int low =1;
        int high = *max_element(position.begin(), position.end()), ans = 0;
        sort(position.begin(), position.end());

        while(low<=high) {
            int mid = low + ( high-low)/2;

            int count =1;
            int check= position[0];

            for(int i=1;i<position.size();i++) {
                if (position[i]-check>=mid) {
                    count++;
                    check = position[i];
                }
            }

            if (count >= m) {
                ans = mid;low = mid+1;
            } else high = mid-1;
            
        }

        return ans;
    }
};