#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
// #define int long long
#define yes cout<<"YES\n"; return;
#define no cout<<"NO\n"; return;
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

class Solution {
    int calculateMinCost(vector<string>& nums, int n, int start, int end) {
        if(nums.size() <= 1)
            return 0;
        int changes = 0;
        vector<pair<int, int>> startPoints = {{start, start},{end-1, start},{end-1, end-1},{start, end-1}};
        vector<pair<int, int>> directions = {{0, 1},{-1, 0},{0, -1},{1, 0}};

        int iterations = n - 1;
        while(iterations) {
            int sum = 0;
            for(int i = 0; i < 4; i++) {
                auto [x, y] = startPoints[i];
                auto [incX, incY] = directions[i];

                sum += nums[x][y] - '0';
                startPoints[i].first += incX;
                startPoints[i].second += incY;
            }
            iterations--;
            changes += min(sum, 4 - sum);
        }
        // for(int i = 0; i < 4; i++) {
        //     auto [x, y] = startPoints[i];
        //     cout<<x<<", "<<y<<endl;
        // }
        // cout<<endl;
        return changes;
    }
    public:
    void solve() {
        int n;
        cin >> n;
        vector<string> nums(n);

        for(int i = 0; i < n; i++)
            cin >> nums[i];
        
        int result = 0;
        int start = 0, end = n;
        while(n > 0) {
            result += calculateMinCost(nums, n, start, end);
            n -= 2;
            start += 1;
            end -= 1;
        }       
        cout<<result<<endl;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

