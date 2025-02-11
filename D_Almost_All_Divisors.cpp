#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> v(n);
        int lcmV = 1;
        int maxNum = 0;
        int minNum = LLONG_MAX;

        for (auto& input : v) {
            cin >> input;
            maxNum = max(maxNum, input);
            minNum = min(minNum, input);
            lcmV = lcm(input, lcmV);
        }
        if(lcmV == maxNum) {
            lcmV *= minNum;
        }
        cout<<lcmV<<endl;
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
