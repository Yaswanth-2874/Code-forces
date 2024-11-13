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
        int n, m;
        cin >> n >> m;

        vector<int> k(n), c(m);
        input(k);
        input(c);

        sort(all(k), greater<int> ());
        vector<pair<int, int>> costs;
        int left = 0;

        for(int i = 1; i <= m; i++)
            costs.push_back({i, c[i-1]});    
        
        int totalCost = 0;

        for(int& ki : k) {
            int pos = ki, cost = c[ki-1];
            if(left < costs.size()) {
                if(pos > costs[left].first) {
                    pos = costs[left].first;
                    cost = costs[left].second;
                    left++;
                }
            }
            // cout<<"Bought position "<<pos<<" for cost "<<cost<<endl;
            totalCost += cost;
        }
        pn(totalCost)
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
