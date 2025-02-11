#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> v(n);
        for (auto& input : v) {
            cin >> input;
        }

        sort(begin(v), end(v));
        int ans = 0;
        int totalSum = accumulate(begin(v), end(v), 0ll);

        for(int i = 0; i < n; i++) {
            int minValue = totalSum - y - v[i];
            int maxValue = totalSum - x - v[i];

            int minValueIndex = lower_bound(begin(v), end(v), minValue) - (begin(v));
            int maxValueIndex = upper_bound(begin(v), end(v), maxValue) - (begin(v));

            ans += maxValueIndex - minValueIndex;
            if(v[i] >= minValue && v[i] <= maxValue)
                ans--;
        }
        cout<<ans/2<<endl;
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
