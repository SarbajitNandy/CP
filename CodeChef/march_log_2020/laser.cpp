#include <bits/stdc++.h>
using namespace std;      
#define endl '\n'
#define MAX 1e9+7  
#define pb(x) push_bacK(x)
#define mk(x,y) make_pair(x,y)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;
typedef pair<int,int64> pr;

pr make_vector(pr p1, pr p2) { // p2 - p1
    return mk((p2.first-p1.first),(p2.second-p1.second));
}

int cross(pr v1, pr v2) { // v1 x v2
    return  ((1ll*v1.first*v2.second) - (1ll*v1.second*v2.first));
}

int check_orientation( pr p1, pr p2, pr p0) { // 1 -> clockwise, -1 -> anti clockwise, 0 -> inline
    int first = cross( make_vector(p2, p0), make_vector(p1,p0));
    
    return first;   
}

int jump=0;
bool check_inter(pr p1, pr p2, pr p3, pr p4) {
    int o1 = check_orientation(p3,p4,p1);
    int o2 = check_orientation(p3,p4,p2);
    
    if (o1==0 || o2==0) jump=1; 
    
    if ((o1>0 && o2>0) || (o1<0 && o2<0)) {
        return false;
    }
    
    int o3 = check_orientation(p1,p2,p3);
    int o4 = check_orientation(p1,p2,p4);
    
    if ((o3>0 && o4>0) || (o3<0 && o4<0)) {
        return false;
    }
    return true;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    
    int t; cin >> t;
    int64 dp[1000001];
    int n,q;
    
    //int64 c, slope;
    int64 y;
    int x1,x2;
    int count;
    while (t--)
    {
        cin >> n >> q;
        for(int i=1;i<=n;i++) {
            cin >> dp[i];
        } 
        
        //while (q--)
        //{
            //count=0;
            //cin >> x1 >> x2>>y; // y = c
            //pr p3 = mk(x1,y);
            //pr p4 = mk(x2,y);
            //int x= min(x2,n-1);
            //for(int i=min(x1-1,1);i<=x;i++) {
                //if (check_inter(mk(i,dp[i]), mk(i+1,dp[i+1]), p3,p4)) { 
                    //count++; 
                    //i+=jump; jump=0;
                    //cout << "i: " << i << endl; 
                //}
            //}
            //cout << count << endl;
            
        //}
        
        while (q--) {
            count=0;
            cin >> x1 >> x2 >> y;
            int x = min(x2-1,n-1);
            for(int i=max(x1-1,1);i<=x;i++) {
                if ( (y>=dp[i] && y<=dp[i+1]) || (y<=dp[i] && y>=dp[i+1]) ) count++;
                if (y==dp[i] || y==dp[i+1]) i++;
                    
            }
            cout << count << endl;
        }
    }

}
