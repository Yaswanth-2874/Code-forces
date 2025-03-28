#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int k;
        cin >> k;

        vector<pair<int, int>> res;
        res.push_back({0, 0});
        int currentPairs = 0;
        int nextVal = 1;

        while(currentPairs + nextVal <= k) {
            currentPairs += nextVal;
            res.push_back({nextVal++, 0});
        }

        k -= currentPairs;
        currentPairs = 0; nextVal = 1;
        

        while(currentPairs + nextVal <= k) {
            currentPairs += nextVal;
            res.push_back({1, nextVal++});
        }

        k -= currentPairs;
        int neg = -1;
        currentPairs = 0; nextVal = 1;
        int maxi = 1e7;

        while(currentPairs + nextVal <= k) {
            currentPairs += nextVal++;
            res.push_back({2, maxi--});
        }

        k -= currentPairs;
        res.push_back({-1, -1});

        while(k--) {
            auto [a, b] = res.back();

            if(k % 2)
                res.push_back({a, a-1});
            else
                res.push_back({b-1, b}); 
        }

        // cout<<"Remaining k : "<<k<<endl;

        cout<<res.size()<<endl;
        /* Print array*/ {
            for(auto& [val1, val2] : res) {
                cout <<val1<<" "<<val2<<endl;
            }
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
