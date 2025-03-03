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
        vi cnt(n+1,0);
        for(int i : x) cnt[i]++;
        int l = -1,r = -1,len = 0;
        int curr_l = -1,curr_r = -1;
        int i = 0;
        while(i < n){
            // cout << curr_l << " " << curr_r << " ";
            // cout << l << " " << r << " ->" << endl;
            if(cnt[x[i]] > 1){
                if(curr_r != -1 && curr_r - curr_l + 1 > len){
                    l = curr_l; r = curr_r;
                    len = r-l+1;
                    curr_l = -1;curr_r = -1;
                }
                else{
                    curr_l = -1;curr_r = -1; 
                }
            } 
            else{
                if(curr_l == -1){
                    curr_l = curr_r = i;
                }
                else{
                    curr_r++;
                }
            }
            i++;
        }
        
        if(curr_r != -1 && curr_r - curr_l + 1 > len){
            l = curr_l; r = curr_r;
            len = r-l+1;
        }
        if(l == -1 && r == -1){
            cout << 0 << endl;
        }
        else{
            cout << l+1 << " " << r+1 << endl;
        }
    }
}