#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> v(n);
        int posSum = 0, negSum = 0;

        for (auto& input : v) {
            cin >> input;
            posSum += input > 0 ? input : 0;
            negSum += input < 0 ? -input : 0;
        }

        vector<int> newV;
        bool firstPos = v[0] > 0;
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            if(firstPos && v[i] < 0) {
                firstPos = false;
                newV.push_back(sum);
                sum = 0;
            }
            if(!firstPos && v[i] > 0) {
                firstPos = true;
                newV.push_back(sum);
                sum = 0;
            }

            sum += v[i];
        }

        if(sum)
            newV.push_back(sum);

        // merge all the positives and negatives first
        // select all positives and last negative
        // now add a negative and remove the positive -> repeat
        // Similar for all negatives, track max

        int ans = posSum;
        int curr = ans;

        for(int i = (int)newV.size() - 1; i >= 0; i--) {
            curr += (-1 * newV[i]);
            ans = max(ans, curr);
        }

        curr = negSum;
        for(int i = 0; i < newV.size(); i++) {
            curr += newV[i];
            ans = max(ans, curr);
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
