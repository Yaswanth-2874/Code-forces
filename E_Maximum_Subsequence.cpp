#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    vector<int> v;
    int n, m;

    void generateSubset(vector<int>& subset, int last, int index, int sum) {
        if(index > last) {
            subset.push_back(sum % m);
            return;
        }

        generateSubset(subset, last, index+1, sum+v[index]);
        generateSubset(subset, last, index+1, sum);
    }
    public:
    void solve() {
        cin >> n >> m;

        v.resize(n);
        for (auto& input : v) {
            cin >> input;
        }

        vector<int> subset1, subset2;
        generateSubset(subset1, (n-1)/2, 0, 0);
        generateSubset(subset2, n-1, (n-1)/2 + 1, 0);
        int maxAns = 0;

        sort(begin(subset2), end(subset2));
        for(int i = 0; i < subset1.size(); i++) {
            int currSum = subset1[i];
            int target = m-1 - currSum;

            int index = upper_bound(begin(subset2), end(subset2), target) - begin(subset2);
            if(index != 0)
                index--;
            maxAns = max((currSum + subset2[index]) % m, maxAns);
        }

        cout<<maxAns<<endl;
        
    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
