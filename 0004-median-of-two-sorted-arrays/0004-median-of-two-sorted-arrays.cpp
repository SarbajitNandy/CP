

class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        int nm = n+m;
        int fid, sid;

        sid = nm/2;
        fid = sid-1;

        int first = 0, second = 0;
        int cnt = -1, i = 0, j = 0;

        while (i < n && j < m) {
            cnt++;
            if (arr1[i] < arr2[j]) {
                if (cnt == fid)
                    first = arr1[i];
                if (cnt == sid)
                    second = arr1[i];
                i++;
            } else {
                if (cnt == fid)
                    first = arr2[j];
                if (cnt == sid)
                    second = arr2[j];
                j++;
            }
        }

        if (cnt < fid || cnt < sid) {
            while (i < n) {
                cnt++;
                if (cnt == fid)
                    first = arr1[i];
                if (cnt == sid)
                    second = arr1[i];
                i++;
            }
            while (j < m) {
                cnt++;
                if (cnt == fid)
                    first = arr2[j];
                if (cnt == sid)
                    second = arr2[j];
                j++;
            }
        }
        
        if (nm &1) return second;
        else return (first+second)*1.0/2;
    }
};