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
        string s;
        cin >> s;
        vi x(3,0);
        int sum = 0;
        for(int i = 0;i < s.size();i++){
            sum += s[i] - '0';
            if(s[i] == '2') x[0]++;
            if(s[i] == '3') x[1]++;
        }
        if(sum % 9 == 0){
            cout << "YES" << endl;
        }
        else{
            int rem = 9 - (sum % 9);
            if(rem == 2 && x[0] >= 1){
                cout << "YES" << endl;
            }
            else if(rem == 4 && x[0] >= 2){
                cout << "YES" << endl;
            }
            else if(rem == 6 && (x[0] >= 3 || x[1] >= 1)){
                cout << "YES" << endl;
            }
            else if(rem == 8 && (x[0] >= 4 || (x[0] >= 1 && x[1] >= 1))){
                cout << "YES" << endl;
            }
            else if(rem == 1 && (x[0] >= 5 || (x[0] >= 2 && x[1] >= 1))){
                cout << "YES" << endl;
            }
            else if(rem == 3 && (x[0] >= 6 || (x[0] >= 3 && x[1] >= 1) || x[1] >= 2)){
                cout << "YES" << endl;
            }
            else if(rem == 5 && (x[0] >= 7 || (x[0] >= 4 && x[1] >= 1) || (x[0] >= 1 && x[1] >= 2))){
                cout << "YES" << endl;
            }
            else if(rem == 7 && (x[0] >= 8 || (x[0] >= 5 && x[1] >= 1)|| (x[0] >= 2 && x[1] >= 2))){
                cout << "YES" << endl;
            }
            else{
                cout << "NO"<< endl;
            }
        }
    }
}