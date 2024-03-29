// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
#include <thread>
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
#define mk make_pair
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

class Node{
    public:
    string name;
    bool locked;
    ll lockedDescendantCount;
    Node* parent;
    vector<Node*> children;
    ll uId;

    Node(string n) {
        name=n;
        locked=false;
        lockedDescendantCount=0;
        parent =NULL;
        uId=-1;
    }

    void add_children(Node *child) {
        child->parent = this;
        children.push_back(child);
    }

    bool lock(ll uId) {
        // cout << this->name << endl;

        if (this->locked){
            return false;
        }
        if (this->lockedDescendantCount>0) return false;
        Node * parent = this->parent;
        while(parent!=NULL) {
            if (parent->locked) return false;
            parent=parent->parent;
        }
        // sm 
        parent = this->parent;
        while(parent!=NULL) {
            parent->lockedDescendantCount++;
            parent=parent->parent;
        }
        this->locked=true;
        this->uId=uId;
        return true;
    }

    bool unlock(ll uId) {
        cerr << this->locked << endl;

        if (!this->locked) return false;

        if (this->uId!=uId) return false;
        Node *parent = this->parent;
        while(parent) {
            if (parent->locked) return false;
            parent=parent->parent;
        }
        //sm
        parent = this->parent;
        while(parent) {
            parent->lockedDescendantCount--;
            parent=parent->parent;
        }
        this->locked=false;
        this->uId=-1;
        return true;

    }

    bool upgradeLock(ll uId) {
        // cout << this->name << endl;

        if (this->locked || this->lockedDescendantCount==0) return false;
        // check if it has locked parents 
        Node *parent = this->parent;
        while(parent) {
            if (parent->locked) return false;
            parent=parent->parent;
        }

        bool ans = this->lockDecWithUid(uId);
        if (!ans)return false;
        this->unlockAllRequired(uId);
        return this->lock(uId);
        // Node *parent = this->parent;
        // while(parent) {
        //     parent->lockedDescendantCount--;
        //     parent=parent->parent;
        // }
        // this->locked=true;
        // this->uId=uId;
        // return true;
    }

    bool lockDecWithUid(ll uId) {
        bool ans=true;
        for(auto child: this->children) {
            // cout << child->name << " " << child->uId << endl;
            if (child->locked && child->uId!=uId) return false;
            else {
                ans= child->lockDecWithUid(uId);
                if (!ans) return false;
            }
        }
        return ans;
    }

    void unlockAllRequired(ll uId) {
        for(auto child: this->children) {
            if (child->locked ) {
                child->unlock(uId);
            } else child->unlockAllRequired(uId);
            
        }
    }
    void traverse(int pos = 0) {
        cout << this->name  << " " << pos << endl;

        for(auto child : this->children) {
            child->traverse(pos+1);
        }
    }
};

void lk(Node* root, long long uId) {
    bool ans = root->lock(uId);
    cout<< "Lock on " << root->name << " " << (ans ? "true" : "false") << endl;

}

void ulk(Node* root, long long uId) {
    bool ans = root->unlock(uId);
    cout << "Unlock on " << root->name << " "<< (ans ? "true" : "false") << endl;


}

void upgrdlk(Node* root, long long uId) {
    bool ans = root->upgradeLock(uId);
    cout << "Upgrade Lock on " << root->name << " " << (ans ? "true" : "false") << endl;
}
void solve()
{
    ll n,m,q; cin >> n >> m >> q;
    vector<Node*> nodes;
    vector<thread> threadList;
    map<string,Node*> mp;
    string name;
    for(ll i=0;i<n;i++) {
        cin >> name;
        Node *n = new Node(name);
        nodes.push_back(n);
        mp[name]=n;
    }

    ll parent = 0, child=1, count=0;

    while (child <n) {
        nodes[parent]->add_children(nodes[child]);
        count++;
        if (count==m) {parent++;count=0;}
        child++;
    }

    Node *root = nodes[0];
    // root->traverse();
    // return ; // END
    int type; ll uId; 
    bool ans;
    while (q--) {
        cin >> type >> name >> uId;
        // cout << type << name << uId;

        // switch(type){
        //     case 1: ans= mp[name]->lock; break;
        //     case 2: ans= mp[name]->unlock; break;
        //     case 3: ans= mp[name]->upgradeLock; break;
        // }

        switch(type){
            case 1: threadList.pb(thread(lk, mp[name],uId)); break;
            case 2: threadList.pb(thread(ulk, mp[name],uId)); break;
            case 3: threadList.pb(thread(upgrdlk, mp[name],uId)); break;
        }
        // thread nt(lk, mp[name], uId);
        // nt.join();

        // cout << ((ans)?"true":"false") << endl;
        // ans=false;
    }
    for(auto &th: threadList) {
        if (th.joinable()) {
            // cout << "Thread is joinable\n";
            th.join();
        }
    }


}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    cout << fixed << setprecision(0);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
        cout << nline;
    }
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
// `Keep It Simple Stupid!