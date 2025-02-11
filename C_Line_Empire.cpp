#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, a, b;
        cin >> n >> b >> a;

        vector<int> v(n);
        for (auto& input : v) {
            cin >> input;
        }
        int minCost = 0, currPos = 0;

        for(int i = 0; i < n; i++) {
            minCost += (v[i] - currPos) * a;
            int changeCapital = (v[i] - currPos) * b;
            int costReduction = (n - (i+1)) * (v[i] - currPos) * a;
            // cout<<"Cost for changing capital : "<<changeCapital<<endl;
            // cout<<"Cost reduced by changing capital : "<<costReduction<<endl;

            if(costReduction >= changeCapital) {
                minCost += changeCapital;
                currPos = v[i];
            }
        }
        cout<<minCost<<endl;
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
