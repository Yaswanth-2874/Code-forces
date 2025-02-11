#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> v(n), prefixXor(1, 0);
        for (auto& input : v) {
            cin >> input;
            prefixXor.push_back(prefixXor.back() ^ input);
        }

        string b;
        cin >> b;

        int q;
        cin >> q;

        int xor0 = 0, xor1 = 0;
        for(int i = 0; i < n; i++) {
            if(b[i] - '0' == 0) {
                xor0 ^= v[i];
            } else {
                xor1 ^= v[i];
            }
        }

        while(q--) {
            int type;
            cin >> type;

            if(type == 2) {
                int val;
                cin >> val;

                if(val == 1)
                    cout<<xor1<<" ";
                else
                    cout<<xor0<<" ";
            } else {
                int l, r;
                cin >> l >> r;

                int xorrange = prefixXor[r] ^ prefixXor[l-1];
                xor0 ^= xorrange;
                xor1 ^= xorrange;
            }
        }
        cout<<endl;

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
