#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#pragma endregion

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        if(n % 2 == 0) {
            int cream = 1;
            for(int i = 0; i < n/2; i++) {
                cout<<cream << " "<<cream<<" ";
                cream++;
            }
            cout<<endl;
            return;
        }

        if(n <= 26)
            pn(-1);
        
        vector<int> ans(n, -1);
        ans[0] = 1e6;
        ans[9] = 1e6;
        ans[25] = 1e6;
        ans[22] = 1e6-1; 
        ans[26] = 1e6-1;

        int num = 1;
        int remainingReps = 2;

        for(int i = 1; i < n; i++) {
            if(ans[i] != -1)
                continue;
            if(remainingReps == 0) {
                num++;
                remainingReps = 2;
            }
            ans[i] = num;
            remainingReps--;
        }
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
