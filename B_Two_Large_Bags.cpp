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
        int highest = *max_element(begin(v), end(v));

        vector<int> freq(1001, 0);
        for(auto& current : v) 
            freq[current]++;

        for(int i = 1; i <= highest; i++) {
            if(freq[i] >= 2) {
                int extra = freq[i] - 2;
                freq[i+1] += extra;
                freq[i] = 2;
            } else if (freq[i] == 1) {
                /* Print no*/ {
                    cout<<"No\n";
                    return;
                }
            }
        }

        if(freq[highest + 1] % 2 == 0)
            /* Print yes*/ {
                cout<<"Yes\n";
                return;
            };
        /* Print no*/ {
            cout<<"No\n";
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
