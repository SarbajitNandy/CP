class Solution {
public:

    void recur(int index, string s, int n, vector<string>& temp, vector<vector<string>>& res) {
        if (index==n) {
            res.push_back(temp); return;
        }

        for(int i=index; i<n;i++) {
            if (isPalindrome(s, index, i)) {
                temp.push_back(s.substr(index, i-index+1));
                recur(i+1, s, n,temp, res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> res;

        recur(0,s,s.length(),temp, res);
        return res;
    }

    bool isPalindrome(string s, int start, int end) {
        int left=start, right = end;

        while(left<right) {
            if (s[left]!=s[right]) return false;
            left++; right--;
        }

        return true;

    }

};