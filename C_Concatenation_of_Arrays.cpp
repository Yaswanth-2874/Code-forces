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

// THIS WONT WORK 100% SURE

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        set<pair<int, int>> s;
        while(n--) {
            int a, b;
            cin >> a >> b;
            // If i insert it like a , b how many changes
    
            s.insert({a, b});
        }
        for(auto& [a, b] : s)
            cout<<a<<" "<<b<<" ";
        cout<<endl;
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

