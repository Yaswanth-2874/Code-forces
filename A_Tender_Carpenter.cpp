#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> v(n);
        for (auto& input : v) {
            cin >> input;
        }

        // sort(begin(v), end(v));
        for(int i = 0; i < n-1; i++) {
            int second = v[i+1];
            int first = v[i];
            if(second < first) {
                swap(second, first);
            }
            if(second == first)
                {
                    cout<<"YES\n";
                    return;
                }

            if(second < 2 * first)
                {
                    cout<<"YES\n";
                    return;
                }
        }
        {
            cout<<"NO\n";
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
