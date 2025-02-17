#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define int long long int
#define MOD 1000000007
// #define sort(x) sort(x.begin(),x.end())
#define minHeap priority_queue<int, vector<int>,greater<int>>

void arrin(vector<int>&x , int size){ for(int i = 0;i < size;i++){ cin >> x[i]; } } 
void arrout(vi &x,int n){for(int i = 0;i < n;i++){ cout << x[i] << " "; } cout << endl;}

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

int32_t main(){
    int t; cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vvi grid(n,vi(m));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                cin >> grid[i][j];
            }
            sort(begin(grid[i]),end(grid[i]));
        }
        vector<pii> temp(n);
        unordered_map<int,int> mp;
        vi ans;
        for(int i = 0;i < n;i++){
            temp[i].first = i;
            temp[i].second = grid[i][0];
            mp[grid[i][0]] = i;
        }
        sort(begin(grid),end(grid));
        bool check = true;
        int now = -1;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[j][i] > now){
                    now = grid[j][i];
                    if(ans.size() < n){
                        ans.push_back(mp[now]);
                    }
                }
                else{
                    check = false;
                    break;
                }
            }
        }
        if(check){
            for(int i = 0;i < n;i++){
                cout << ans[i]+1 << " ";
            }
            cout << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}