class Solution {
public:
    int sumOfDivisiors(int num) {
        int cnt = 0, sum = 0;
        for (int i=1; i <= sqrt(num); i++) {
            if (num % i == 0) {
                if (i*i == num) {
                    cnt++;
                    sum += i ;
                } else  {
                    cnt+=2;
                    sum += i + (num/i);
                } 
            }

            if (cnt > 4)
                return 0;
        }
        if (cnt==4) return sum;
        return 0;
        
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (int e : nums) {
            sum += sumOfDivisiors(e);
        }

        return sum;
    }
};