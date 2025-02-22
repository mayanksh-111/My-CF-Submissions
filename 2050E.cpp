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

vvi dp;
int solve(string &a,string& b,string& c,int i,int j){
    if(dp[i][j] != -1) return dp[i][j];
    if(i == a.size()){
        int count = 0;
        return count;
    }
    else if(j == b.size()){
        int count = 0;
        return count;
    }

    int cha = (a[i] != c[i+j]) + solve(a,b,c,i+1,j);
    int chb = (b[j] != c[i+j]) + solve(a,b,c,i,j+1);

    return dp[i][j] = min(cha,chb);
}
int32_t main(){
    int t; cin >> t;
    while(t--){
        string a,b,c; cin >> a >> b >> c;
        dp.clear();
        dp.resize(a.size()+1,vi(b.size()+1,-1));
        int count = 0;
        for(int j = b.size()-1;j >= 0;j--){
            int k = a.size() + j ;
            count += (b[j] != c[k]);
            dp[a.size()][j] = count;
        }
        count = 0;
        for(int j = a.size()-1;j >= 0;j--){
            int k = b.size() + j ;
            count += (a[j] != c[k]);
            dp[j][b.size()] = count;
        }
        cout << solve(a,b,c,0,0) << endl;
    }
}