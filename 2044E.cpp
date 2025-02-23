#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define int long long int
#define MOD 1000000007
#define sort(x) sort(x.begin(),x.end())
#define minHeap priority_queue<int, vector<int>,greater<int>>

void inputarray(vector<int>&x , int size){ for(int i = 0;i < size;i++){ cin >> x[i]; } } 
void printarray(vi &x,int n){for(int i = 0;i < n;i++){ cout << x[i] << " "; } cout << endl;}

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

int po(int n,int k){
    int res= 1;
    while(k){
        k--;
        res *= n;
    }
    return res;
}
int32_t main(){
    int t; cin >> t;
    while(t--){
        int k,l1,r1,l2,r2; cin >> k >> l1 >> r1 >> l2 >> r2;
        int ans = 0;
        int ind = 1;
        while(ind <= r2){
            int l = l2%ind == 0 ? l2/ind : l2/ind + 1;
            int r = r2/ind;
            // cout << ind << " " << l << " " << r << endl;
            l = max(l,l1);
            r = min(r,r1);
            if(l <= r1 && r >= l1 && l <= r){
                // cout << ind << " " << l << " " << r << endl;
                ans += r-l+1;
            }
            if(ind*k == ind) break;
            ind *= k;
        }
        cout << ans << endl;
    }
}