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

int32_t main(){
    int tests; cin >> tests;
    while(tests--){
        int n; cin >> n;
        vi x(n); arrin(x,n);
        vi pre(n,0),suf(n,0);
        pre[0] = (x[0] > 0) ? x[0] : 0;
        for(int i = 1;i < n;i++){
            if(x[i] > 0){
                pre[i] = pre[i-1] + x[i];
            }
            else{
                pre[i] = pre[i-1];
            }
        }
        suf[n-1] = x[n-1] < 0 ? -x[n-1] : 0;
        for(int i = n-2;i >= 0;i--){
            if(x[i] < 0){
                suf[i] = suf[i+1] - x[i];
            }
            else{
                suf[i] = suf[i+1];
            }
        }
        // arrout(pre); arrout(suf);
        int ans = 0;
        for(int i = 0;i < n;i++){
            ans = max(ans,pre[i]+suf[i]);
        }
        cout << ans << endl;
    }
}