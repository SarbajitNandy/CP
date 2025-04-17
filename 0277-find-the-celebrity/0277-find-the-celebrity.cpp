/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int N = n;
        int candidate = 0;

        for (int i = 1; i < N; ++i) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }

        for (int i = 0; i < N; ++i) {
            if (i != candidate) {
                if (!knows(i, candidate) || knows(candidate, i)) {
                    return -1;
                }
            }
        }

        return candidate;
    }
};