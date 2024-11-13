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

// (0 1), (1 5), (3 4), (5 6),(8 10)
// Keep track of valid min position and max position for every jump i make

class Solution {
    bool canJump(vector<pair<int, int>>& segments, int k) {
        pair<int, int> pos = {0, 0};

        for(int i = 0; i < segments.size(); i++) {
            pair<int, int> jumpRange = {pos.first - k, pos.second + k};
            int minPos = max(jumpRange.first, segments[i].first);
            int maxPos = min(jumpRange.second, segments[i].second);

            if(minPos > maxPos)
                return false;
            
            pos = {minPos, maxPos};
        }
        return true;
    }
    public:
    void solve() {
        int n;
        cin >> n;

        vector<pair<int, int>> segments;
        for(int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            segments.push_back({l, r});
        }
        int left = 0, right = LLONG_MAX - 1;
        while(left <= right) {
            int mid = left + (right - left)/2;
            if(canJump(segments, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        pn(right + 1);
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
