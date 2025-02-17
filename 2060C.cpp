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
        int n,k;
        cin >> n >> k;
        vi x(n); arrin(x,n);
        unordered_map<int,int> cnt;
        for(int i : x){
            cnt[i]++;
        }
        // for(auto &it : cnt){
        //     cout << it.first << "->" << it.second << endl;
        // }
        set<int> temp;
        for(int i : x) temp.insert(i);
        int count = 0;
        for(auto &it : cnt){
            if(temp.find(k - it.first) != temp.end()){
                if(k - it.first == it.first){
                    count += it.second; 
                }
                else{
                    count += min(it.second,cnt[k - it.first]);
                }
            }
        }
        cout << count/2 << endl;
    }
}