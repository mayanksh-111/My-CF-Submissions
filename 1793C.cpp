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
        vi found(n+1,0);
        int m = 1,M = n;
        int l = 0,r = n-1;
        while(l < r){
            if(x[l] == m || x[l] == M){
                found[x[l]]++;
                if(x[l] == m) m++;
                if(x[l] == M) M--;
                l++;
            }
            if(x[r] == m || x[r] == M){
                found[x[r]]++;
                if(x[r] == m) m++;
                if(x[r] == M) M--;
                r--;
            }
            else if(x[r] != m && x[r] != M && x[l] != m && x[l] != M){
                break;
            }
        }
        if(l < r){
            cout << l+1 << " " << r+1 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}