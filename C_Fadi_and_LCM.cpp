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

// Time complexity is sqrt(n) * log(n), should get accepted
class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        for(int i = sqrtl(n); i >= 1; i--) {
            if(n % i == 0 && gcd(n/i, i) == 1) {
                cout<<i<<" "<<n/i<<endl;
                return;
            }
        }
        
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

