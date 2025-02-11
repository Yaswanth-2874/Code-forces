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

        int zeroes = count(begin(st), end(st), '0');
        int ones = n - zeroes;

        if(zeroes && ones) {
            cout<<1<<endl;
            return;
        }
        cout<<max(zeroes, ones)<<endl;
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
