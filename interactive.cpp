#include <bits/stdc++.h>
using namespace std;

#define int long long
#define printAns(ans) {cout<<"! "<<ans<<endl; return;}


class Solution {
    int query(int a, int b) {
        cout<<"? "<<a<<" "<<b<<endl;
        cout.flush();
        int res;
        cin >> res;
        return res;
    }
    public:
    void solve() {

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

