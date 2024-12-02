class Solution {
public:
    int ans = 0;

    void merge(vector<int>& ar, int low, int mid, int high) {
        int left = low, right = mid + 1, tempInd = 0;
        int r = right, counter = 0;
        vector<int> temp(high - low + 1);

        while (left <= mid && right <= high) {
            if (ar[left] <= ar[right]) {

                while (r <= high && (ar[left] > (long)2 * ar[r]))
                    counter++, r++;

                ans += counter;
                temp[tempInd++] = ar[left++];
            } else
                temp[tempInd++] = ar[right++];
        }

        while (left <= mid) {
            while (r <= high && (ar[left] > (long)2 * ar[r]))
                counter++, r++;
            ans += counter;
            temp[tempInd++] = ar[left++];
        }

        while (right <= high)
            temp[tempInd++] = ar[right++];

        for (int i = 0; i < tempInd; i++)
            ar[low++] = temp[i];
    }

    int countPairs(vector<int>& arr, int low, int mid, int high) {
        int right = mid + 1;
        int cnt = 0;

        for (int i = low; i <= mid; i++) {
            while (right <= high && arr[i] > 2LL * arr[right])
                right++;
            cnt += right - (mid + 1);
        }

        return cnt;
    }

    int mergeSort(vector<int>& arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            int cnt = 0;

            cnt += mergeSort(arr, left, mid);
            cnt += mergeSort(arr, mid + 1, right);
            cnt += countPairs(arr, left, mid, right);

            merge(arr, left, mid, right);

            return cnt;
        }

        return 0;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();

        return mergeSort(nums, 0, n - 1);
    }
};