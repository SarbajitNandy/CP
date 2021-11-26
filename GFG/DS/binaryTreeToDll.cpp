/*
    Author : prashant_th18
                            :)
*/
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define MOD 1000000007
#define ull unsigned long long
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vpl vector<pl>
#define vx(x) vector<x>
#define pb push_back
#define all(v) begin(v), end(v)
#define PI 3.1415926535897932384626
#define fl(i, si, ei) for(ll i = si; i < ei; ++i)
#define nline '\n'
#define space ' '
#define ff first
#define ss second
#define sz(v) ((ll)(v).size())
#define set_bits __builtin_popcountll
#ifndef ONLINE_JUDGE 
#define debug(x) cerr << #x << " : "; _print(x); cerr << nline;
#else
#define debug(x)
#endif
// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */ 
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */ 
template <typename T> void _print(vector <T> v) { cerr << "[ "; for(auto myval : v) cerr << myval << " "; cerr << "]"; }
template <typename T1, typename T2> void _print(vector <T1, T2> v) { cerr << "[ "; for(auto myval : v) cerr << myval.ff << space << myval.ss << " "; cerr << "]"; }
template <typename T> void _print(set <T> v) { cerr << "[ "; for(auto myval : v) cerr << myval << " "; cerr << "]"; }
template <typename T1, typename T2> void _print(map<T1, T2> v) { cerr << "[ "; for(auto myval : v) cerr << myval.ff << space << myval.ss << " "; cerr << "]"; }
void _print(int a) {cerr << a;}
void _print(ll a) {cerr << a;}
void _print(ull a) {cerr << a;}
void _print(char a) {cerr << a;}
void _print(string a) {cerr << a;}
void _print(double a) {cerr << a;}

class node {
    public:
        int value;
        node *prev, *next;

    public:
        node(int value) {this->value=value;this->prev=NULL;this->next=NULL;}
};

class DLL {
    public:
        node *head,*tail;

        DLL(){
            this->head=NULL; this->tail=NULL;
        }

        void insert_at_end(int value) {
            node *newNode = new node(value);

            if (tail==NULL && head==NULL) {
                head=tail=newNode;
            } else {
                tail->next=newNode;
                newNode->prev=tail;
                tail=newNode;
            }
        }

        void show( int direction=1 ) {

            node* point = direction >0 ? head : tail ;
            while (point!=NULL) { cout << point->value << " "; point=(direction > 0 ? point->next : point->prev);}
            cout << endl;
        }
};



int solve(int idx, int (*graph)[2], DLL* dll, int *nodes)
{
    if (idx==-1) return 0;

    int &left = graph[idx][0];
    int &right = graph[idx][1];

    debug(left); 
    if (left!= -1) solve(left, graph, dll, nodes);

    debug(idx); debug(nodes[idx]);
    dll->insert_at_end(nodes[idx]);

    debug(right);
    if (right!= -1) solve(right, graph, dll, nodes);

    return 0;

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    
    int n; cin >> n;
    int nodes[n]; for(int i=0;i<n;i++) cin >> nodes[i];

    int graph[n][2];
    for(int i=0;i<n;i++) {
        cin >> graph[i][0] >>graph[i][1]; 
    }

    DLL *mydll = new DLL();

    solve(0,graph, mydll, nodes);

    mydll->show();





    
    

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
// `Keep It Simple Stupid!