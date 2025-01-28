class Solution {
public:
    const int CODES[16] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096, 8192, 16384, 32768};
    vector<int> grayCode(int n) {
        vector<int> res = {0,1};
        int i=1;
        while(--n) {
            size_t s = res.size();
            for(int k=s-1;k>=0;k--) {
                res.push_back(res[k] + CODES[i]);
            }
            i++;
        }

        return res;
    }
};