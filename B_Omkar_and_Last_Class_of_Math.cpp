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

class Solution {
    vector<int> findAns(int n) {
        if(n % 2 == 0)
            return {n/2, n/2};
        int greatestFactor = 1;
        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) {
                int maxF = max(i, n/i);
                // cout<<maxF<<endl;
                greatestFactor = max(greatestFactor, maxF);
            }
        }
        if(greatestFactor == 1) {
            return {1, n-1};
        }
        int newN = n/greatestFactor;
        vector<int> ans = findAns(newN);
        ans[0] *= greatestFactor;
        ans[1] *= greatestFactor;

        return ans;
    }
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> ans = findAns(n);
        print(ans);
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

