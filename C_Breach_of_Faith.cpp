#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    // let a1 = a2 - a3 + a4 - a5
    // a2 = a1 + (a3 - a4) + a5

    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> v(2*n);
        for (auto& input : v) {
            cin >> input;
        }

        vector<int> res(2*n + 1);
        sort(begin(v), end(v));

        int a2 = 0;
        int minIndex = 0, maxIndex = 2*n - 1;

        for(int i = 0; i < 2*n+1; i++) {
            if(i == 1)
                continue;
            if(i % 2 == 0)
                a2 += res[i] = v[maxIndex--];
            else
                a2 -= res[i] = v[minIndex++];
        }

        res[1] = a2;
        /* Print array*/ {
            for(auto& val : res) {
                cout << val << " ";
            }
            cout << endl;
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
