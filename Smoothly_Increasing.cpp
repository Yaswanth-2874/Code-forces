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

        string ans(n, '0');
        if(n >= 32)
            /* Print number*/ {
                cout<<ans<<endl;
                return;
            }
        
        for(int toSkip = 0; toSkip < n; toSkip++) {
            vector<int> skipped(n-1);
            int index = 0;
            for(int i = 0; i < n; i++) {
                if(i == toSkip)
                    continue;
                skipped[index++] = v[i];
            }
            int prevDiff = 0;
            bool isOne = true;
  
            
            while(skipped.size() > 1) {
                for(int i = 1; i < skipped.size(); i++) {
                    skipped[i-1] = skipped[i] - skipped[i-1];
                    if(skipped[i-1] <= 0) {
                        isOne = false;
                        // break;
                    }
                }
                skipped.pop_back();
            }

            if(isOne)
                ans[toSkip] = '1';
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
