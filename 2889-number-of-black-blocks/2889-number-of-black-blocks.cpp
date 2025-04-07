class Solution {

    private: 
        long long fn(int x, int y, int m ) {
            return 1LL * m*x + y;
        } 
public:

    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        map<long long,long long> mp;

        int dx[4] = {0,0,-1,-1};
        int dy[4] = {0,-1,0,-1};

        for(auto coord : coordinates) {
            for(int i = 0;i<4;i++) {
                int nr = coord[0] + dx[i];
                int nc = coord[1] + dy[i];

                if (nr >=0 && nr < m-1 && nc >=0 && nc < n-1) {
                    // string s = to_string(nr) + '_' + to_string(nc);
                    mp[fn(nr,nc,n)]++;
                }
            }
        }

        vector<long long> res(5,0); 

        long long total = 0;
        for(auto e : mp) {
            res[e.second]++;
            total++;
        }

        res[0] = 1LL*(m-1)*(n-1) - total;



        return res;
    }
};