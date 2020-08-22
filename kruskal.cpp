#include<bits/stdc++.h>
#include<vector>
#include<math.h>
#define loop(i,a,n) for(int i=a;i<n;i++)
#define revloop(i,a,n) for(int i=a-1;i>=n;i--)
#define max 100000
#define ll long long 
#define l long 
using namespace std;
typedef struct{
    int v1,v2,w;
}edge;
int n,m; 
edge arr[max];
int parent[max+1],vrank[max+1];
//comparator function 
bool fun(edge i, edge j){
    return i.w<j.w ;   //sort in assending order 
}
void makeset(int i){parent[i]=i;}
int find(int i){
    if(parent[i]==i) return i;
    else {
        int temp=find(parent[i]);
        parent[i]=temp;
        return temp;
    }
}
void set_union (int i, int j){
    int pi = find(i);
    int pj = find(j);
    if(vrank[pi]>vrank[pj])parent[pj]=pi;
    else if(vrank[pi]<vrank[pj])parent[pi]=pj;
    else {parent[pj]=pi;vrank[pi]++;}
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin>>n>>m;
    int a,b,w;
    loop(i,0,m){
        cin>>a>>b>>w;
        arr[i].v1=a;arr[i].v2=b;arr[i].w=w;
    }
    sort(arr,arr+m,fun); //sort the edges wrt fun
    //loop(i,0,m){cout<<arr[i].v1<<" "<<arr[i].v2<<" "<<arr[i].w<<endl;}
    //cout<<endl;
    //starting implementation of kruskal 
    
    //calling make set for every vertex
    loop(i,1,n+1)makeset(i); 
    //setting rank of evewry vertex 
    loop(i,1,n+1)vrank[i]=1;
    //it's time join the edges such that it don't form a loop
    ll sum=0;
    loop(i,0,m){
        //if they belong to the same disjoint set or not 
        if(find(arr[i].v1)!=find(arr[i].v2) ) 
        {
            //cout<<arr[i].v1<<" "<<arr[i].v2<<endl;
            set_union(arr[i].v1,arr[i].v2);
            sum+=arr[i].w;
        }
    }
    cout<<sum<<endl;  
    return 0;
}