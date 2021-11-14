#include <bits/stdc++.h>
typedef long long int ll;
#define p_2 pair<ll,ll> 
#define p_3 pair<p_2,ll> 
using namespace std;
// ll x,y;
// void go_left() {
// 	y--;
// }
// void go_right() {
// 	y++;
// }
// void go_up() {
// 	x--;
// }
// void go_down() {
// 	x++;
// }

// bool compare( p_3 a,p_3 b ) {
// 	// cout << (a.first<=b.first && a.second < b.second)<< endl;
// 	// cout << a.first << " " << a.second << " " << b.first << " " << b.second << endl;
// 	return a.first.first<b.first.first || (a.first.first==b.first.first && a.first.second < b.first.second);
// }

int main(int argc, char const *argv[])
{
	// freopen("in.txt", "r", stdin);
	// int t; cin >> t;
	// vector<p_3> arr;
	// ll a,b;
	// int d[t];
	// int i=0;
	// while (i<t) {
	// 	cin >> a >> b;
	// 	arr.push_back(make_pair(make_pair(a,b),i));
	// 	i++;
	// }

	// sort(arr.begin(),arr.end(), compare);

	// for (auto item : arr) {
	// 	// cout << "1 ";
	// 	cout << item.first.first << " " << item.first.second << endl;
	// }

	// x=1;y=2;
	// ll term = 2;
	// ll counter=2;
	// for( auto item: arr) {
	// 	if (item.first.first == 1 && item.first.second==1) { d[item.second]=1; continue;}
	// 	if (item.first.first == 1 && item.first.second==2) { d[item.second]=2; continue;}
	// 	while (true) {
	// 		if (x==item.first.first && y==item.first.second) {d[item.second]=counter; break;}

	// 		if ( !(term&1) && x==term && y==1ll) {go_down();term++;}
	// 		else if ( (term&1) && x==1ll && term==y) {go_right(); term++;}
	// 		else {
	// 			if (term&1) {
	// 				if (term==x && term==y) {go_up();}
	// 				else if (term==x) {go_right();}
	// 				else {go_up();}
	// 			} else {
	// 				if (term==x && term==y) {go_left();}
	// 				else if (term==y) {go_down();}
	// 				else {go_left();} 
	// 			}
	// 		}
	// 		counter++;
	// 		// cout << x << " " << y << endl;
	// 	}
	// }

	// for(int x : d) {
	// 	cout << x << endl;
	// }
	int t; cin >> t;
	ll a,b;

	while (t--) {
		cin >> a >> b;
		ll term = max(a,b);
		ll end=1;
		end = term*term;
		
		ll n_el = 2*term-1;
		if (term&1ll) {
			if (term==a && term>=b) {
				cout << (end - (n_el-b)) << endl;
			} else {
				cout << (end-a+1) << endl;
			}
		} else {
			if (term==b && term>=a) {
				cout << (end- (n_el-a)) << endl;
			} else {
				cout << (end-b+1) << endl;
			}
		}

	}
	
}