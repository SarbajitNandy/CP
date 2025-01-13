class Solution {
public:
    int mySqrt(int n) {
        int low = 1, high = n;

            while(low <= high) {
                  int mid = low + (high-low)/2;

                  long long v = 1ll * mid*mid;
                  if (v == n) return mid;

                  if (v > n) {
                        high = mid-1;
                  } else low = mid+1;
            }

            return floor(high);
    }
};