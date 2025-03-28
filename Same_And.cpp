#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    // values should lie between 0 and m
    public:
    void solve() {
        int n, m;
        cin >> n >> m;

        // bitwise and of any two numbers in the seq should be n and no 2 numbers should be equal
        int minNum = n;
        set<int> ans;
        ans.insert(n);

        for(int i = 62; i >= 0; i--) {
            int bit = 1ll << i;
            if(bit & n)
                continue;
            if((bit | n) <= m) {
                ans.insert((bit | n));
            }
        }

        if(ans.size() == 1) {
            /* Print number*/ {
                cout<<-1<<endl;
                return;
            }
        }
        cout<<ans.size()<<endl;
        for(auto it : ans) {
            cout<<it<<" ";
        }
        cout<<endl;
    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
