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

int32_t main(){
    int t; cin >> t;
    while(t--){
        int m,a,b,c; cin >> m >> a>> b >> c;
        int r1 = min(m,a);
        int r2 = min(m,b);
        int rem = min(2*m - r1-r2,c);
        cout << r1+r2+rem << endl; 
    }
}