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
        int total = accumulate(begin(v), end(v), 0ll);
        sort(begin(v), end(v));

        int q;
        cin >> q;
        while(q--) {
            int people, capacity;
            cin >> people >> capacity;

            int index = lower_bound(begin(v), end(v), people) - begin(v);
            int choice1 = LLONG_MAX, choice2 = LLONG_MAX;

            if(index != n && v[index] == people) {
               int remaining = total - v[index];
               cout<<max(0ll, capacity - remaining)<<endl;
               continue;
            }

            if(index != n) {
                int remaining = total - v[index];
                choice1 = max(0ll, capacity - remaining);
            }
            if(index > 0) {
                int remaining = total - v[index - 1];
                choice2 = max(0ll, capacity - remaining) + people - v[index - 1];
            }

            cout<<min(choice1, choice2)<<endl;
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
