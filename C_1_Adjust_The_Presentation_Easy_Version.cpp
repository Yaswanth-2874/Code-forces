#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YA\n"; return;}
#define no {cout<<"TIDAK\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}

class Solution {
    public:
    void solve() {
        int n, m, q;
        cin >> n >> m >> q;

        vector<int> order(n);
        input(order);
        set<int> visited;
        int left = 0;
        bool ans = true;

        for(int i = 0; i < m; i++) {
            int q;
            cin >> q;
            if(visited.find(q) != visited.end())
                continue;
            if(q == order[left]) {
                left++;
                visited.insert(q);
            } else {
                ans = false;
            }
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

