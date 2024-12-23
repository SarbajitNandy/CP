class Solution {
public:
    const int MOD = 1e9 + 7;
    long long gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }

    int nthMagicalNumber(int n, int a, int b) {
        long long left = min(a, b);
        long long right = left * n * 1LL;
        long long lc = lcm(a, b);
        long long ans;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (((mid / a) + (mid / b) - (mid / lc)) < n)
                left = mid + 1;
            else {
                right = mid - 1;
                ans = mid;
            }
        }

        return ans % MOD;
    }
};