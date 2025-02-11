#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (auto& input : a) {
            cin >> input;
        }
        vector<int> prefixSum;
        vector<int> diffArray(n+1, 0);
        vector<int> teaDrunk(n, 0);

        for (auto& input : b) {
            cin >> input;
            if(prefixSum.empty())
                prefixSum.push_back(input);
            else 
                prefixSum.push_back(prefixSum.back() + input);
        }
        int extraTea = 0;

        for(int i = 0; i < n; i++) {
            int tea = a[i] + extraTea;
            int upperIndex = upper_bound(begin(prefixSum), end(prefixSum), tea) - begin(prefixSum);
            // tea definitely gets completed at upperBound Index
            
            int prev = upperIndex > 0 ? prefixSum[upperIndex - 1] : 0;
            int remainingTea = tea - prev;

            diffArray[i] += 1;
            diffArray[upperIndex] -= 1;

            if(upperIndex != n) {
                // cout<<"Person "<<upperIndex<<" drank extra tea of "<<(remainingTea)<<" from "<<(i+1)<<endl;
                teaDrunk[upperIndex] += remainingTea;
            }
            extraTea += b[i];
        }
        int fullDrinks = 0;

        for(int i = 0; i < n; i++) {
            fullDrinks += diffArray[i];

            teaDrunk[i] += fullDrinks * b[i];
            cout<<teaDrunk[i]<<" ";
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
