#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        string st;
        cin >> st;

        if(st.size() > 10) {
            cout<<st[0]<<st.size()-2<<st[st.size()-1]<<endl;
        } else {
            cout<<st<<endl;
        }
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
