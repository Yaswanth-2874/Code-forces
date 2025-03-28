#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        string st1, st2;
        cin >> st1 >> st2;

        vector<tuple<int, int, int>> operations;
        for(int i = 1; i < n; i+= 2) {
            if(st1[i] == st2[i] && st1[i-1] == st2[i-1])
                continue;
            if(st1[i] != st2[i] && st1[i-1] != st2[i-1]) {
                operations.push_back({1, i, i+1});
                continue;
            }
            if(st1[i] == st2[i] && st1[i-1] != st2[i-1]) {
                operations.push_back({1 , i, i});
                continue;
            }
            if(st1[i] != st2[i] && st1[i-1] == st2[i-1]) {
                operations.push_back({1 , i+1, i+1});
                continue;
            }
        }
        if(n % 2 && st1[n-1] != st2[n-1]) {
            operations.push_back({1, n, n});
        } 

        cout<<operations.size()<<endl;
        for(auto& [x, y, z] : operations)
            cout<<x<<" "<<y<<" "<<z<<endl;
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
