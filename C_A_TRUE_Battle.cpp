#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>

// At each new turn, bob will try to create a zero while alice will try to remove the zero
// And statements get higher priority
// Be greedy, bob will always use and operations, alice will always use or
// inorder for alice to win, she needs to kill all zeroes
// at each bob turn , one 1 will be killed for sure(if there is atleast one zero)
// atleast two consecutive ones guarantee victory for alice

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if(s[0] == '1' || s[n-1] == '1')
            yes;

        int consectiveOnes = 0;
        int maxCons = 0;

        char prev = '#';

        for(auto& ch : s) {
            if(ch == '1' && prev == '1')
                yes;
            prev = ch;
        }
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

