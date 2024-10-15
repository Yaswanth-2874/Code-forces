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

// This approach was really excellent but i was not able to figure it out on my own :(
// NEXT TIME, I SHOULD BE ABLE TO

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        vector<int> nums(n);
        input(nums);
        vector<bool> visited(n);
        int totalPairs = 0;

        for(int i = 31; i >= 0; i--) {
            int currentBit = 1LL << i;
            int currentPairs = 0;
            for(int i = 0; i < n; i++) {
                if(!visited[i] && (currentBit & nums[i])) {
                    currentPairs++;
                    visited[i] = true;
                }
            }
            // cout<<"Pairs for "<<i<<" are "<<currentPairs<<endl;
            totalPairs += (currentPairs * (currentPairs - 1)) / 2;
        }
        cout<<totalPairs<<endl;
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

