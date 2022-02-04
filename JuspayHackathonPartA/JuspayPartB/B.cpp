
#include <bits/stdc++.h>
#include <thread>
#include<unistd.h>
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
    bool mutex;

    Node(string n) {
        name=n;
        locked=false;
        lockedDescendantCount=0;
        parent =NULL;
        uId=-1;
        mutex=1;
    }


    void wait(bool& sem) {
        while(sem==false);
        sem=false;
    }

    void signal(bool &sem) { sem=true;}

    int getLocked(){ 
        wait(mutex);
        bool ret = this->locked;
        signal(mutex);
        return ret;
    }
    void setLocked(bool val){ 
        wait(mutex);
        this->locked=val;
        signal(mutex);
    }

    ll getLockedDescendents(){ 
        wait(mutex);
        ll ret= this->lockedDescendantCount;
        signal(mutex);
        return ret;
    }
    void incLockedDescendents(){ 
        wait(mutex);
        this->lockedDescendantCount++;
        signal(mutex);
    }
    void decLockedDescendents(){ 
        wait(mutex);
        this->lockedDescendantCount--;
        signal(mutex);
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
    bool lockV2(ll uId) {
        // cout << this->name << endl;
        wait(mutex);
        if (this->locked){
            return false;
        }
        if (this->lockedDescendantCount>0) return false;
        Node * parent = this->parent;
        while(parent!=NULL) {
            cerr << "parent " << parent->name ; 
            if (parent->getLocked()) { cerr << "False\n";return false;}
            else {cerr<<"True\n";}
            parent=parent->parent;
        }
        // sm 
        parent = this->parent;
        while(parent!=NULL) {
            parent->incLockedDescendents();
            parent=parent->parent;
        }
        this->locked=true;
        this->uId=uId;
        signal(mutex);

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
class th_result{
public:
    bool result;
    int type;
    string name;
    ll uId;

    th_result(int type, string n, ll u) { this->type=type; name=n; uId=u;}

};

map<thread::id, th_result*> result;


void performLockOp(Node* root, ll uId){
    bool res = root->lockV2(uId);
    result[this_thread::get_id()]->result = res ;
    // cout << root->name << " LOCK" << " " << res << endl;//sleep(1);
}
void performUnLockOp(Node* root, ll uId){
    bool res = root->unlock(uId);
    result[this_thread::get_id()]->result = res ;

    // cout << root->name << " UNLOCK"<< " " << root->unlock(uId) << endl;//sleep(1);
}
void performUpgradeLockOp(Node* root, ll uId){

    bool res = root->upgradeLock(uId);
    result[this_thread::get_id()]->result = res ;
    // cout << root->name << " UPGRADE LOCK" << " " << root->upgradeLock(uId) << endl;//sleep(1);
}


void solve()
{
    ll n,m,q; cin >> n >> m >> q;
    vector<Node*> nodes;
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
    vector<thread> th_list;
    
    while (q--) {
        cin >> type >> name >> uId;
        switch(type){
            case 1:  th_list.pb(thread(performLockOp,mp[name],uId)); break;
            case 2:  th_list.pb(thread(performUnLockOp,mp[name],uId)); break;
            case 3:  th_list.pb(thread(performUpgradeLockOp,mp[name],uId)); break;
        }

        result[th_list.back().get_id()] = new th_result(type, name, uId);
    }

    for( thread& e: th_list) e.join();

    for(pair<thread::id, th_result*> each: result){
        cout << each.second->type << " " << each.second->name << " " << (each.second->result?"True":"False") << endl;
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