class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int n = arr.size();

        int id = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if (id == n) id--;
        int left,right;
        if (arr[id]==x) {
            left=id-1;
            right = id+1;
            res.push_back(arr[id]); k--;
        } else {
            left = id-1; right=id;
        }

        while(k--) {
            if (left >=0 && right<n ) {
                if (abs(arr[left]-x) <= abs(arr[right]-x)) {
                    res.push_back(arr[left--]);
                } else {
                    res.push_back(arr[right++]);
                }
            } else if (left>=0) {
                res.push_back(arr[left--]);
            } else {
                res.push_back(arr[right++]);
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};