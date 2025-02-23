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

void arrin(vector<int>&x , int size){ for(int i = 0;i < size;i++){ cin >> x[i]; } } 
void arrout(vi &x,int n){for(int i = 0;i < n;i++){ cout << x[i] << " "; } cout << endl;}

ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }

int32_t main(){
    int t; cin >> t;
    while(t--){
        int a,b,c,d; cin >> a >> b >> c >> d;
        int t1 = a+b;
        int t2 = d-c;
        int t3 = c-b;
        int count = 1;
        count += (t1 == t2) + (t2 == t3) + (t1 == t3);
        if(count == 4) count--;
        cout << count << endl;
    }
}
