class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        
        // for(int i=0;i<n;i++) cost[i]=gas[i]-cost[i];
        
        int i,t=0;
        long long ans;
        
        while (t<n){
            if ((gas[t]-cost[t])<0)t++;
            else{
                ans = (gas[t]-cost[t]);
                i=(t+1)%n;
                while(i!=t){
                    // cout << t << " " << i << endl;
                    ans+=(gas[i]-cost[i]);i=(i+1)%n;
                    if (ans<0) break;
                }
                if (ans>=0) return t;
                
                if (i<=t) t=n;
                else t = i;
            }
        }
        
        return -1;
    }
};