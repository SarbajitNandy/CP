class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k,0);

        for(int e : arr) {
            mp[((e%k)+k)%k]++;
        }

        for(int i = 0 ; i<k;i++) {
            if (mp[i]==0) continue;

            int rem = (k-i)%k;
            if (mp[rem]==0 || mp[rem]!=mp[i] || (i==rem && mp[i]&1)) return false;
        }
        return true;
    }
};