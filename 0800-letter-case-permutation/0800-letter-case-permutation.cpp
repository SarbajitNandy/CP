class Solution {
public:
    void recur(int index, vector<char>& s, int n, vector<string>& res) {
        if (index == n) {
            string r(s.begin(), s.end());
            res.push_back(r);
            return;
        }

        recur(index + 1, s, n, res);
        if (!('0' <= s[index] && s[index] <= '9')) {
            s[index] =
                islower(s[index]) ? toupper(s[index]) : tolower(s[index]);
            recur(index + 1, s, n, res);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<char> arr;
        for (char e : s) {
            arr.push_back(e);
        }

        vector<string> res;

        recur(0, arr, s.size(), res);

        return res;
    }
};