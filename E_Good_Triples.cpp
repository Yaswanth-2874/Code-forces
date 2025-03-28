#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    int sigma(int n) {
        return (n * (n + 1)) / 2;
    }
    public:
    void solve() {
        // each digit has a certain weightage
        // 0 has sigma(1), 1 has sigma(2) and so on

        string st;
        cin >> st;

        int ans = 1;
        for(int i = 0; i < st.size(); i++) {
            int digit = st[i] - '0';
            ans *= sigma(digit+1);
        }

        cout<<ans<<endl;
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
