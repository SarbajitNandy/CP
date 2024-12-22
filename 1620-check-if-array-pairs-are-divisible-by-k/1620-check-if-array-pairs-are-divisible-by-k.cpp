class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int> mp;

        for(int e : arr) {
            mp[((e%k)+k)%k]++;
        }

        for(auto e : mp) {
            int rem = ((k-e.first) + k)%k;

            if (!mp.contains(rem) || mp[rem]!=e.second || (e.first==rem && e.second&1)) return false;
        }
        return true;
    }
};