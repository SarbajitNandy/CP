class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        int activeIndices[3] = {-1,-1,-1};

        for(int i=0;i<s.length();i++) {
            activeIndices[s[i]-'a'] = i;

            if (activeIndices[0]!=-1 && activeIndices[1]!=-1 && activeIndices[2]!=-1 ) {
                count += 1 + min({activeIndices[0],activeIndices[1],activeIndices[2]});
            }
        }

        return count;
    }
};