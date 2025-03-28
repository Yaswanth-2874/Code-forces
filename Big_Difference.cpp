#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;

        if(k >= n) {
            cout<<-1<<" "<<-1<<endl;
            return;
        }

        int first = 2;
        int last = n - !(n%2);

        if(last - first < k) {
            cout<<-1<<" "<<-1<<endl;
            return;
        }

        cout<<first<<" "<<last<<endl;
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
