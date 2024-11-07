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


// TESTING TO SEE IF I GET TLE USING UNORDERED_SET (Yes TLE ON using unordered_set)

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        unordered_set<int> unique;
        int sum = 0;
        bool ans = false;

        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if(i%2 == 0)
                sum += num;
            else
                sum -= num;
            if(unique.find(sum) != unique.end() || sum == 0)
                ans = true;
            unique.insert(sum);
        }

        if(ans)
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

