class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        deque<int> res;
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
                    res.push_front(arr[left--]);
                } else {
                    res.push_back(arr[right++]);
                }
            } else if (left>=0) {
                res.push_front(arr[left--]);
            } else {
                res.push_back(arr[right++]);
            }
        }

        return vector<int>(res.begin(), res.end());
    }
};