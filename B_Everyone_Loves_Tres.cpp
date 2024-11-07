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

// only even
// 

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        if(n % 2 == 0) {
            for(int i = 0; i < n-2; i++)
                cout<<3;
            cout<<66<<endl;
            return;
        }
        if(n <= 4)
            pn(-1);
        for(int i = 0; i < n-4; i++) {
            cout<<3;
        }
        cout<<6366<<endl;

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

