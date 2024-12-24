class Solution {
public:
    vector<int> evenOddBit(int n) {
        int odd = 0, even=0;
          bool f = false;

          while(n>0) {
               if (n&1) {
                    if (f) {
                         even++;
                    } else odd++;
               }
               f=!f;
               n>>=1;
          }

          return {odd,even};
    }
};