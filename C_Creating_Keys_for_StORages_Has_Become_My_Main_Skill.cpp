#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    bool check(int numA, int numB) {
        return (numA | numB) == numA;
    }
    public:
    void solve() {
        int n, x;
        cin >> n >> x;

        vector<int> res;
        set<int> exists;
        int xorV = 0;

        for(int i = 0; i < n; i++) {
            if(check(x, i) == false)
                break;
            res.push_back(i);
            xorV |= i;
        }

        while(res.size() < n) {
            res.push_back(x);
        }
        if(xorV != x) {
            res.pop_back();
            res.push_back(x);
        }
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
