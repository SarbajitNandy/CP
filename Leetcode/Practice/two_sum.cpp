class Solution {
public:
    static bool comparePair(pair<int,int> &a, pair<int,int> &b) {return a.first < b.first;}
    vector<int> twoSum(vector<int>& nums, int target) {
        
        /* Solution 1*/
//         vector<int> res(2,0);
        
//         vector<pair<int,int>> num1;
//         for(int i=0;i<nums.size();i++) num1.push_back(make_pair(nums[i],i));
        
//         sort(num1.begin(),num1.end(), comparePair );
        
//         // for(auto each : num1) {
//         //     cout << each.first << " " << each.second << endl;
//         // }
        
//         auto lt=num1.begin();auto rt= num1.end()-1;
        
//         int p = 0;
//         while (lt<rt) {
//             p=lt->first+rt->first;
//             if (p==target) { res[0]=lt->second;res[1]=rt->second; break;}
//             else if (p>target) {rt--;}
//             else lt++;
//         }
        
        /* Solution 2*/
        map<int,int> dp;
        map<int,int>::iterator it;
        for(int i=0;i<nums.size();i++) {
            it = dp.find(target-nums[i]);
            if (it!=dp.end()) {
                return vector<int>{it->second, i};
            }
            dp[nums[i]]=i;
        }
        
       
        return vector<int>{0,(int)nums.size()};
    }
};