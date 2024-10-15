#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
// #define int long long
#define yes {cout<<"ALICE\n"; return;}
#define no {cout<<"BOB\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}

// CONDENSED MY LOGIC AFTER ALL OBSERVATIONS
// ALICE ONLY WINS IN ONCE CASE, DRAW ONLY IN ONE CASE, REMAINGING ALL BOB WINS
// ALICE ONLY WINS IF STRING SIZE IS ODD AND MID IS 0

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        string num;
        cin >> num;
        int totalZeroes = count(all(num), '0');
        if(totalZeroes == 0) {
            cout<<"DRAW"<<endl;
            return;
        }
        if(totalZeroes == 1)
            no;
        if(n%2 && num[n/2] == '0')
            yes;
        no;

    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

