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
        int n, _;
        cin >> n >> _;

        vector<int> a(n, 1);
        vector<int> b(n);

        for(int i = 0; i < n-1; i++)
            cin >> a[i+1];
        input(b);

        sort(all(a));
        sort(all(b));

        int leftB = 0;
        int k = 0;

        for(int leftA = 0; leftA < n; leftA++) {
            while(leftB < n && a[leftA] >= b[leftB]) {
                leftB++;
                k++;
            }
            leftB++;
        }
        pn(k);
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
