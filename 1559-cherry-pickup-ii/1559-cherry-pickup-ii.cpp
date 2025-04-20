class Solution {
public:
    int _n,_m;
    vector<vector<int>> _grid;
    vector<vector<vector<int>>> cache;


    int dfs(int i, int j1, int j2) {
        if (j1 < 0 || j1 >= _m || j2 < 0 || j2 >= _m) return -1e8;

        if (i==_n-1) {
            if (j1==j2) {
                return _grid[i][j1];
            } else { return _grid[i][j1] + _grid[i][j2];}
        }

        if (cache[i][j1][j2]!=-1) return cache[i][j1][j2];

        int maxi = -1e8;

        for(int dx = -1;dx <=1; dx++) {
            for(int dy=-1;dy<=1;dy++) {
                int nj1 = j1 + dx;
                int nj2 = j2 + dy;
                int val = 0;
                if (j1 == j2) {
                    val = _grid[i][j1];
                } else {
                    val=  _grid[i][j1] +  _grid[i][j2];
                }

                val += dfs(i+1, nj1, nj2);

                maxi = max(maxi, val);
            }
        }

        return cache[i][j1][j2]=maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        _n = n;_m=m;

        _grid = grid;

        cache = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(m,0)));

        for(int j1 = 0;j1<m;j1++) {
            for(int j2=0;j2<m;j2++) {
                int val = 0;

                if (j1==j2) val = grid[n-1][j1];
                else val = grid[n-1][j1] + grid[n-1][j2];

                cache[n-1][j1][j2] = val;
            }
        }


        for(int i=n-2;i>=0;i--) {
            for(int j1 = 0;j1<m;j1++) {
                for(int j2=0;j2<m;j2++) {
                    int maxi = -1e8;
                    for(int dx = -1;dx <=1; dx++) {
                        for(int dy=-1;dy<=1;dy++) {
                            int nj1 = j1 + dx;
                            int nj2 = j2 + dy;

                            
                            if (nj1<0 || nj1>=m || nj2 <0 || nj2>=m) {
                                continue;
                            }
                            int val = 0;

                            if (j1 == j2) {
                                val = grid[i][j1];
                            } else {
                                val =  grid[i][j1] +  grid[i][j2];
                            }

                            val += cache[i+1][nj1][nj2];

                            maxi = max(maxi, val);
                        }
                    }

                    cache[i][j1][j2] = maxi;
                }
            }
        }

        return cache[0][0][m-1];

    }
};