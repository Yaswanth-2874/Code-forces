#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
// #define int long long
#define yes cout<<"YES\n"; return;
#define no cout<<"NO\n"; return;
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

// Solution referred :/

class Solution {
    public:
    void solve() {
        int n, d, k;
        cin >> n >> d >> k;
        vector<int> start(n+1),end(n+1);
 
        while(k--) {
            int a,b;
            cin >> a >> b;
            start[a]++;
            end[b]++;
        }
    
        for (int i=0;i<n;i++) {
            start[i+1] += start[i];
            end[i+1] += end[i];
        }
    
        int max = 0, least = 1e9;
        int maxIndex = 0, minIndex = 0;
        
        for (int i=d;i<=n;i++){
            int current = start[i] - end[i-d];
            if (current > max) {
                max = current; 
                maxIndex = i-d+1;
            }
            if (current < least) {
                least = current;
                minIndex = i-d+1;
            }
        }
        cout<<maxIndex<<" "<<minIndex<<endl;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

