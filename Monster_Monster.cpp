#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    vector<int> v;
    int n, x;

    bool check(int val) {
        int inc = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] + inc > val)
                return false;
            inc += x;
        }
        return true;
    }
    public:
    void solve() {
        cin >> n >> x;

        int left = 0, right = LLONG_MAX;
        for(int i = 0; i < n; i++) {
            int val;
            cin >> val;
            v.push_back(val);
        }
        sort(begin(v), end(v), greater<int> ());

        while(left <= right) {
            int mid = left + (right - left)/2;
            if(check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout<<right+1<<endl;
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
