class Solution {
private:
    string mirror(string left, bool isOdd) {
        string rev = left;

        if (isOdd) {
            rev.pop_back();
        }
        reverse(rev.begin(), rev.end());
        return left + rev;
    }

public:
    string nearestPalindromic(string n) {
        int m = n.length();
        long long actual = stoll(n);

        vector<long long> candidates;

        candidates.push_back((long)pow(10, m)+1);
        candidates.push_back((long)pow(10, m-1)-1);

        int prefixLength = (m+1)/2;
        long long  prefixVal = stoll(n.substr(0, prefixLength));
        
        for(int i=-1;i<=1;i++) {
            string val = to_string(prefixVal + i);
            string mirrorval = mirror(val, m&1);
            candidates.push_back(stoll(mirrorval));
        }
        long long candidate = -1;
        long long diff = LONG_LONG_MAX;

        for(long long can: candidates) {
            if(can==actual) continue;
            if (abs(can-actual) < diff) {
                candidate = can;
                diff = abs(can-actual); 
            }
        }

        return to_string(candidate);
    }
};