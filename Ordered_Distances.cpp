#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> x(n);
        for (auto& input : x) {
            cin >> input;
        }

        vector<int> y(n);
        for (auto& input : y) {
            cin >> input;
        }

        for(int pivot = 0; pivot < n; pivot++) {
            vector<pair<int, int>> v;
            for(int num : x) {
                v.push_back({abs(x[pivot] - num), num});
                // cout<<v.back().first<<" "<<v.back().second<<" , ";
            }
            // cout<<endl;
            sort(begin(v), end(v));
            int index = 0;
            bool found = true;

            for(auto& [_, expected] : v) {
                // cout<<expected<<" ";
                if(expected != y[index++]) {
                    found = false;
                    break;
                }
            }
            // cout<<endl;

            if(found)
            /* Print number*/ {
                cout<<pivot+1<<endl;
                return;
            }
        }
        cout<<-1<<endl;

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
