#include <bits/stdc++.h>
using namespace std;        
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> c(n);
    vector<char> t(n);
    long long A = 0, B = 0;
    for (int i = 0; i < n; i++) {
      cin >> c[i] >> t[i];
      if (t[i] == 'A') {
        A += c[i];
      } else {
        B += c[i];
      }
    }
    long long s = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      long long new_s;
      if (t[i] == 'A') {
        new_s = s + B * c[i];
        if (s < 0 && new_s >= 0 && new_s % B == 0) {
          ans++;
        }
        if (s > 0 && new_s <= 0 && new_s % B == 0) {
          ans++;
        }
      } else {
        new_s = s - A * c[i];
        if (s < 0 && new_s >= 0 && new_s % A == 0) {
          ans++;
        }
        if (s > 0 && new_s <= 0 && new_s % A == 0) {
          ans++;
        }
      }
      s = new_s;
    }
    if (A == 0 || B == 0) {
      ans = A + B;
    }
    cout << ans << '\n';
  }
  return 0;
}

