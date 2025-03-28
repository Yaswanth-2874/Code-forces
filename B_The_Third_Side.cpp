#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> v(n);
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& input : v) {
            cin >> input;
            pq.push(input);
        }

        int ans = 0;
        while(pq.size() > 1) {
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();

            int ans = top1 + top2 - 1;
            pq.push(ans);
        }

        cout<<pq.top()<<endl;
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
