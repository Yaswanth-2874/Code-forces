#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<vector<int>> mat;
        multiset<int> suffixOnes;
        // same queues can be re-served but its optimal to not re-serve obviously

        for(int i = 0; i < n; i++) {
            vector<int> v(n);
            for (auto& input : v) {
                cin >> input;
            }
            mat.push_back(v);
            int count = 0;

            for(int i = n-1; i >= 0; i--) {
                if(v[i] == 1)
                    count++;
                else
                    break;
            }
            suffixOnes.insert(count);
            // cout<<count<<" ";
        }


        int mex = 0;
        while(mex <= n+1) {
            auto it = suffixOnes.lower_bound(mex);
            if(it == suffixOnes.end()) {
                /* Print number*/ {
                    cout<<mex<<endl;
                    return;
                }
            }
            suffixOnes.erase(it);
            mex++;
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
