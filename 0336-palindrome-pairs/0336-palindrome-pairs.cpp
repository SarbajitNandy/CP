class Solution {
private:
    bool isPalindrome(string s) {
        int n = s.length();

        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1])
                return false;
        }

        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> input) {
        unordered_map<string, int> mp;
        vector<vector<int>> res;

        for (int i = 0; i < input.size(); i++) {
            string k = input[i];
            reverse(k.begin(), k.end());

            mp[k] = i;
        }

        if (mp.find("") != mp.end()) {
            for (int i = 0; i < input.size(); i++) {
                if (mp[""]==i) continue;
                if (isPalindrome(input[i])) {
                    res.push_back({mp[""], i});
                }
            }
        }

        for (int i = 0; i < input.size(); i++) {
            string word = input[i];

            for (int j = 0; j < word.size(); j++) {
                string pre = word.substr(0, j);
                string suff = word.substr(j, word.size() - j);

                if (mp.find(pre) != mp.end() && isPalindrome(suff) &&
                    mp[pre] != i) {
                    res.push_back({i, mp[pre]});
                }

                if (mp.find(suff) != mp.end() && isPalindrome(pre) &&
                    mp[suff] != i) {
                    res.push_back({mp[suff], i});
                }
            }
        }

        return res;
    }
};