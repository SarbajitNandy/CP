#include <bits/stdc++.h>
using namespace std;      
#define endl '\n'
#define MAX 1e9+7  
#define pb(x) push_back(x)
#define mk(x) make_pair(x)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
#define LONG_INT_MAX 0x7fffffffffffffff

typedef long long int ll;
typedef vector<int> vint;
typedef vector<ll> vint64;

const int N = 100;
int n;
int arr[N];
bool vis[N];

int find_max(int left , int right) {
    int mx=-999999,index=-1;
    fore(i,left,right) {
        if (!vis[i] && arr[i]>mx) {mx=arr[i];index=i;}
    }
    return index;
}

int run(int left, int right, int k) {
    int mx, mx_index ;
    forf(i,2) {
        mx_index = find_max(left, right);
    }
}

int main() {
    cin >> n;
    forf(i,n) cin >> arr[i];
}