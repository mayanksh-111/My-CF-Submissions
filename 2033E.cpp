#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define int long long int
#define MOD 1000000007
#define sort(x) sort(x.begin(),x.end())
#define minHeap priority_queue<int, vector<int>,greater<int>>

void arrin(vi&x,int n){ for(int i=0;i<n;i++){cin >> x[i];}}
void arrout(vi&x){for(int i=0;i<x.size();i++){cout<< x[i]<<" ";}cout<< endl;}

ll gcd(ll a,ll b){ if(b==0) return a; return gcd(b, a%b);}
ll lcm(ll a,ll b){ return a/gcd(a,b)*b;}

int gcdExtended(int a, int b, int* x, int* y);

int modInverse(int A, int M) {
    int x, y;
    int g = gcdExtended(A, M, &x, &y);
    if (g != 1)
        return -1;
    else {
        int res = (x % M + M) % M;
        return res;
    }
}

int gcdExtended(int a, int b, int* x, int* y){
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
unordered_map<int,int> mp;
class DSU{
    private:
    public:
    vector<int> par;
    vector<int> sz;
    
     DSU(int n){
        par = vector<int>(n);
        iota(par.begin(), par.end(), 0);
        sz = vector<int>(n, 1);
    }
    
    int find(int u){
        if(par[u] != par[par[u]])
            par[u] = find(par[par[u]]);        
        return par[u];
    }
    
    bool connected(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) 
            return true;
        return false;
    }
    
    bool join(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) 
            return false;
        if(sz[u] <= sz[v]){
            sz[v] += sz[u];
            par[u] = v;
        }else{
            sz[u] += sz[v];
            par[v] = u;
        }
        return true;
    }
    int calc(){
        int ans = 0;
        mp.clear();
        for(int i = 1;i < par.size();i++) mp[par[i]]++;
        for(auto it : mp){
            if(it.second >= 3) ans += (it.second-1)/2;
        }
        return ans;
    }
};
int32_t main(){
    int tests; cin >> tests;
    while(tests--){
        int n; cin >> n;
        vi x(n+1,-1);
        for(int i = 1;i <= n;i++) cin >> x[i];
        DSU ds(n+1);
        vi vis(n+1,0);
        for(int i = 1;i <= n;i++){
            if(vis[i] == 1) continue;
            else{
                int node = i;
                while(vis[node] == 0){
                    vis[node] = 1;
                    bool chc = ds.join(x[node],node);
                    node = x[node];
                }
            }
        }
        // arrout(ds.par);
        cout << ds.calc() << endl;
    }
}