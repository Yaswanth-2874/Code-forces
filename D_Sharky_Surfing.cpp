#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#pragma endregion

class Solution {
    public:
    void solve() {
        int n, m, L;
        cin >> n >> m >> L;

        vector<pair<int, int>> hurdle;
        for(int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            hurdle.push_back({l, r});
        }

        vector<pair<int, int>> powerUps;
        for(int i = 0; i < m; i++) {
            int xi, pi;
            cin >> xi >> pi;
            powerUps.push_back({xi, pi});
        }

        int hurdleIndex = 0, powerUpIndex = 0;
        int ans = 0;
        int k = 1;

        priority_queue<int> pq;

        while(hurdleIndex < n) {
            int hurdlePos = hurdle[hurdleIndex].first;
            int hurdleSize = hurdle[hurdleIndex].second - hurdle[hurdleIndex].first + 1;
            
            while(powerUpIndex < m && powerUps[powerUpIndex].first < hurdlePos) {
                pq.push(powerUps[powerUpIndex++].second);
            }

            while(!pq.empty() && k <= hurdleSize) {
                int top = pq.top();
                pq.pop();
                k += top;
                ans++;
            }

            if(k <= hurdleSize)
                pn(-1);

            hurdleIndex++;
        }
        pn(ans);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}
