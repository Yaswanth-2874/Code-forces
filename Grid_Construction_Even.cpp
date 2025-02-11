#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> v;
        for(int i = 1; i <= n; i++) {
            if(i == (n+1)/2)
                continue;
            v.push_back(i);
        }

        int extra = 1;

        for(int start = 0; start < n; start++) {
            extra = !extra;
            int mid = (n-1)/2;

            if(extra) {
                v[mid] = n/2;
            } else {
                v[mid] = n/2 + 1;
            }
            
            for(int i = start; i < n + start; i++) {
                int index = i % n;
                // cout<<index<<" ";
                if(index != n-1)
                cout<<v[index]<<" ";
                else
                    cout<<extra + n/2<<" ";              
            }
            cout<<endl;
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
