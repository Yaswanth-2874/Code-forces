#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> v(n);
        int total = n * (n + 1)/2, negative = 0;

        for(auto& input : v) {
            cin >> input;
        }

        int currNeg = 0, nextNeg = 0, laterNeg = 0, positiveStreak = 0;

        for(int i = n-1; i >= 0; i--) {
            if(v[i] > 0) {
                positiveStreak++;
            } else {
                currNeg = positiveStreak + 1 + laterNeg;
                laterNeg = nextNeg;
                nextNeg = currNeg;
                positiveStreak = 0;
                // cout<<currNeg<<" "<<nextNeg<<" "<<laterNeg<<endl;
            }
            negative += currNeg;
        }
        cout<<negative<<" "<<total-negative<<endl;
    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
