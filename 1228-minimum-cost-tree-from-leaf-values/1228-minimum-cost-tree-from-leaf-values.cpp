class Solution {
public:
    int mctFromLeafValues(vector<int>& l) {
        // list<int> l(arr.begin(), arr.end());
        
        int sum=0;

        while(l.size()>1){
            int minProd = INT_MAX;
            int id = 0;

            for(int i=1;i<l.size();i++) {
                if (minProd > l[i-1]*l[i]) {
                    minProd = l[i-1]*l[i];
                    id = l[i-1] < l[i] ? i-1 : i;
                }
            }

            sum += minProd;
            l.erase(l.begin() + id);
        }

        return sum;
    }
};