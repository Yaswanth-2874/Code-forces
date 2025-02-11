#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, m;
        cin >> n >> m;

        priority_queue<tuple<int, int, int>> pq;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            int normalSum = 0;

            for(int place = m; place; place--) {
                int num;
                cin >> num;

                sum += place * num;
                normalSum += num;
            }
            pq.push({normalSum, sum, i});
        }

        int maxSum = 0;
        int size = n-1;

        while(!pq.empty()) {
            auto [normalSum, currSum, index] = pq.top();
            pq.pop();
            // cout<<currSum<<" "< <normalSum<<" "<<index<<endl;

            maxSum += currSum + (normalSum * size * m);
            size--;
        }
        /* Print number*/ {
            cout<<maxSum<<endl;
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
