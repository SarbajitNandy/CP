class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int q = queries.size();

        vector<int> res(q,0);
        vector<int> colors(n,0);

        int count = 0;

        for(int i = 0;i<q;i++) {
            int id = queries[i][0];
            int val = queries[i][1];

            if (colors[id]!=0 && id>0 && colors[id-1]==colors[id]) count--;
            if (colors[id]!=0 && id<n-1 && colors[id+1]==colors[id]) count--;

            colors[id]=val;

            if (id>0 && colors[id-1]==colors[id]) count++;
            if (id<n-1 && colors[id+1]==colors[id]) count++;
            res[i] = count;
        }

        return res;
    }
};