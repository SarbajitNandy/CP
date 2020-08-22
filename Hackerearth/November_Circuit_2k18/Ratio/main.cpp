#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;
enum { A=0, B=1};
/*
int main()
{
    int t,k; cin>>t;
    while (t--){
        cin>>k;
        ll arr[2][k],sA=0,sB=0,c=0;
        char ch;
        for(int i=0;i<k;i++){  // Filling data
            cin>>arr[1][i]>>ch;
            if (ch=='A') { arr[0][i]=A; sA+=arr[1][i];}
            else { arr[0][i]=B; sB += arr[1][i];}
        }
        ll gcd = __gcd(sA,sB);
        ll rA = sA/gcd, rB = sB/gcd;
        if (sA==0) { cout<< sB<<endl;}
        else if (sB==0) { cout<<sA<<endl;}
        else {
            int a=1,b=1,jump=0;
            ll fA=0, fB=0,cA=0,cB=0;
            ll f=0;
            while (f<k){
                if (arr[0][f]==A && a==1){
                    //a=0; b=1;
                    cA += arr[1][f];
                    if (arr[0][f+1]==A){ f++;continue;}
                    if (fB!=0 && cB==0) {
                        if (jump==0 && cA>=(fB*rA)) { cA-= (fB*rA); fB=0; c++;}
                        else { jump=0; }
                    }
                    if (!(cA%rA) && !jump) { fA = cA/rA; cA=0; b=1; a=0; jump=0;}
                    else {
                         b=1; a=0;
                        if (jump) { jump=0;}
                        else { jump = 1;}
                    }
                }
                else if (arr[0][f]==B && b==1){
                    cB += arr[1][f];
                    if (arr[0][f+1]==B) { f++;continue;}
                    if (fA!=0 && cA==0) {
                        if (jump==0 && cB>=(fA*rB)) { cB-= (fA*rB); fA=0; c++;}
                        else { jump=0;}
                    }
                    if (!(cB%rB) && !jump) { fB = cB/rB; cB=0; b=0; a=1; jump=0;}
                    else {
                        b=0; a=1;
                        if (jump) { jump=0;}
                        else { jump = 1;}
                    }
                }
                if (fA!=0 && cB>=(fA*rB)){
                    cB-= (fA*rB); fA=0; c++;
                }
                else if (fB!=0 && cA>=(fB*rA)){
                    cA-= (fB*rA); fB=0; c++;
                }
                f++;
            }
            cout<<c<<endl;
        }
    }
    return 0;
}
*/
/*
int main()
{
    int t,k; cin>>t;
    while (t--){
        cin>>k;
        ll arr[2][k],sA=0,sB=0,c=0;
        char ch;
        for(int i=0;i<k;i++){  // Filling data
            cin>>arr[1][i]>>ch;
            if (ch=='A') { arr[0][i]=A; sA+=arr[1][i];}
            else { arr[0][i]=B; sB += arr[1][i];}
        }
        ll gcd = __gcd(sA,sB);
        ll rA = sA/gcd, rB = sB/gcd;
        if (sA==0) { cout<< sB<<endl;}
        else if (sB==0) { cout<<sA<<endl;}
        else {
            int a=1,b=1;
            ll fA=0, fB=0,cA=0,cB=0;
            ll f=0;
            while (f<k){
                if (arr[0][f]==A && a==1){
                    //a=0; b=1;
                    cA += arr[1][f];
                    if (cA<rA && arr[0][f+1]==A){ f++;continue;}
                    if (fB!=0 && cB==0) {
                        if (cA>=(fB*rA)) { cA-= (fB*rA); fB=0; c++;}
                    }
                    if (!(cA%rA)) { fA = cA/rA; cA=0; b=1; a=0;}
                }
                else if (arr[0][f]==B && b==1){
                    cB += arr[1][f];
                    if (cB<rB && arr[0][f+1]==B) { f++;continue;}
                    if (fA!=0 && cA==0) {
                        if (cB>=(fA*rB)) { cB-= (fA*rB); fA=0; c++;}
                    }
                    if (!(cB%rB)) { fB = cB/rB; cB=0; b=0; a=1;}
                }
                f++;
            }
            cout<<c<<endl;
        }
    }
    return 0;
}
*/
/*
int main()
{
    int t,k; cin>>t;
    while (t--){
        cin>>k;
        ll arr[2][k],sA=0,sB=0,c=0;
        char ch;
        for(int i=0;i<k;i++){  // Filling data
            cin>>arr[1][i]>>ch;
            if (ch=='A') { arr[0][i]=A; sA+=arr[1][i];}
            else { arr[0][i]=B; sB += arr[1][i];}
        }
        ll gcd = __gcd(sA,sB);
        ll rA = sA/gcd, rB = sB/gcd;
        if (sA==0) { cout<< sB<<endl;}
        else if (sB==0) { cout<<sA<<endl;}
        else {
            int a=1,b=1,jump=0;
            ll fA=0, fB=0,cA=0,cB=0;
            ll f=0;
            while (f<k){
                if (!jump){
                    if (arr[0][f]==A && a==1){
                        //a=0; b=1;
                        cA += arr[1][f];
                        if (cA<rA && arr[0][f+1]==A){ f++;continue;}
                        if (fB!=0 && cB==0) {
                            if (cA>=(fB*rA)) { cA-= (fB*rA); fB=0; c++;}
                        }
                        if (!(cA%rA)) { fA = cA/rA; cA=0; b=1; a=0;}
                        else { jump=1;}
                    }
                    else if (arr[0][f]==B && b==1){
                        cB += arr[1][f];
                        if (cB<rB && arr[0][f+1]==B) { f++;continue;}
                        if (fA!=0 && cA==0) {
                            if (cB>=(fA*rB)) { cB-= (fA*rB); fA=0; c++;}
                        }
                        if (!(cB%rB)) { fB = cB/rB; cB=0; b=0; a=1;}
                        else { jump=1;}
                    }
                }
                else {
                    if (arr[0][f]==A) {
                        cA += arr[1][f];
                    } else {
                        cB += arr[1][f];
                    }
                    if (!(cA%rA) && !(cB%rB) && (cA/rA)==(cB/rB)) {
                        jump=0; c++; cA=0; cB=0; b=1; a=1;
                    }
                }
                f++;
            }
            cout<<c<<endl;
        }
    }
    return 0;
}
*//*
int main()
{
    int t,k; cin>>t;
    while (t--){
        cin>>k;
        ll arr[2][k],sA=0,sB=0,c=0;
        char ch;
        for(int i=0;i<k;i++){  // Filling data
            cin>>arr[1][i]>>ch;
            if (ch=='A') { arr[0][i]=A; sA+=arr[1][i];}
            else { arr[0][i]=B; sB += arr[1][i];}
        }
        ll gcd = __gcd(sA,sB);
        ll rA = sA/gcd, rB = sB/gcd;
        if (sA==0) { cout<< sB<<endl;}
        else if (sB==0) { cout<<sA<<endl;}
        else {
            ll tR = rA+rB,cA=0,cB=0;
            ll f=0;
            while (f<k){
                if (arr[0][f] == A)
                {
                    cA += arr[1][f];
                }
                else
                {
                    cB += arr[1][f];
                }
                if ((cA+cB)<tR) {
                    f++; continue;
                }
                if (!((cA+cB)%tR))
                {
                    if (!(cA % rA) && !(cB % rB) && (cA / rA) == (cB / rB))
                    {
                        cA=0;cB=0; c++;
                    } else { goto l1;}
                } else {
                   l1: if (arr[0][f]==A){
                        if (!(cB%rB) && cB>=rB && (cA%rA)) {
                            cA-= (cB/rB)*rA; c++; cB=0;
                        }else {
                            f++;
                            continue;
                        }
                    } else {
                        if (!(cA % rA) && cA >= rA){
                            cB-= (cA/rA)*rB; c++; cA=0;
                        } else {
                            f++;
                            continue;
                        }
                    }
                }
                f++;
            }
            cout<<c<<endl;
        }
    }
    return 0;
}
*/
//  Successfully completed solution
// Sample code to perform I/O:
 
cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT
 
// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

 
// Write your code here
#include <bits/stdc++.h>
 
using namespace std;
 
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
