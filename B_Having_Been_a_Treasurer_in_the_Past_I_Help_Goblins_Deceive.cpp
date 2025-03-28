#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        string st;
        cin >> st;

        int hyphen = 0, underscore = 0;
        for(char ch : st) {
            hyphen += ch == '-';
            underscore += ch == '_';
        }

        int div1 = hyphen/2, div2 = hyphen - div1;
        /* Print number*/ {
            cout<<div1 * div2 * underscore<<endl;
            return;
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
