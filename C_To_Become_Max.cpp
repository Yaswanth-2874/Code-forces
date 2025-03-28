#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    vector<int> v;
    int k;

    bool canMake(int target) {
        for(int i = 0; i < v.size(); i++) {
            vector<int> required(v.size(), 0);
            required[i] = target;
            int totalSpent = 0;

            for(int j = i; j < v.size(); j++) {
                if(required[j] <= v[j])
                    break;

                totalSpent += required[j] - v[j];

                if(j == v.size() - 1)
                    totalSpent = 1e10;
                else
                    required[j+1] = (required[j] - 1);
                
            }
  
            // cout<<"Total spent for "<< i << " to make "<<target<<" is "<<totalSpent<<endl;

            if(totalSpent <= k)
                return true;
        }
        return false;
    }
    public:
    void solve() {
        int n;
        cin >> n >> k;
        v.resize(n);

        for (auto& input : v) {
            cin >> input;
        }
        int ans = 0;
        int left = 0, right = *max_element(begin(v), end(v)) + k;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(canMake(mid)) {
                ans = mid;
                left  = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        /* Print number*/ {
            cout<<ans<<endl;
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
