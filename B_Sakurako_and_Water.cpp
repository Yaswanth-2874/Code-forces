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
    public:
    void solve() {
        int n;
        cin >> n;
        int ans = 0;

        vector<vector<int>> mat;

        for(int i = 0; i < n; i++) {
            vector<int> nums(n);
            input(nums);
            mat.push_back(nums);
        }

        map<int, int> freq;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int diff = j-i;
    
                if(mat[i][j] < 0) {  
                    // cout<<mat[i][j]<<endl;
                    // if(freq.find(diff) != freq.end())
                    //     freq
                    freq[diff] = max(freq[diff], -mat[i][j]);
                }
            }
        }

        for(auto [num, _] : freq){
            // cout<<_<<endl;
            ans += _;}
        cout<<ans<<endl;
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

