class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0]==b[0]) return a[1]<b[1];
        else return a[0]>b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compare);

        list<vector<int>> res;

        for(auto p : people) {
            auto it = res.begin();
            advance(it, p[1]);
            res.insert(it,p);
        }

        return vector<vector<int>>(res.begin(), res.end());
    }
};