#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        
        for(auto interval : intervals) {
            if(ans.empty() || ans.back()[1] < interval[0])
                ans.push_back(interval);
            else
                ans.back()[1] = max(interval[1],ans.back()[1]);
        }
        
        return ans;
    }
    public:
    void solve() {
        int n, m;
        cin >> n >> m;

        vector<int> x(n);
        for (auto& input : x) {
            cin >> input;
        }

        vector<int> r(n);
        map<int, vector<vector<int>>> ranges;
        int ans = 0;
        for (auto& input : r) {
            cin >> input;
        }

        for(int i = 0; i < n; i++) {
            int centre = x[i], radius = r[i];
            // cout<<"centre is "<<centre<<" and max radius is "<<radius<<endl;
            for(int i = 0; i <= radius; i++) {
                int left = centre, right = centre + radius;
                int firstValid = LONG_MAX, lastValid = LONG_MAX;
                while(left <= right) {
                    int mid = left + (right - left)/2;
                    // cout<<"Point is "<<mid<<endl;
                    int eq = (mid - centre) * (mid - centre) + i*i - radius*radius;
                    if(eq > 0) {
                        right = mid - 1;
                        // cout<<"Lies outside"<<endl;
                    } else {
                        lastValid = mid;
                        left = mid + 1;
                        // cout<<"Lies inside"<<endl;
                    }
                }
                int distance = lastValid - centre;
                firstValid = centre - distance;
                // cout<<firstValid<<" , "<<lastValid<<endl;                
                // cout<<"Lies inside"<<endl;
                ranges[i].push_back({firstValid, lastValid});
            }
        }

        for(auto& [y, interval] : ranges) {
            vector<vector<int>> mergedInterval = merge(interval);
            for(int i = 0; i < mergedInterval.size(); i++) {
                int size = mergedInterval[i][1] - mergedInterval[i][0] + 1;
                // cout<<mergedInterval[i][0]<<" "<<mergedInterval[i][1]<<" and this point is present at "<<y<<endl;
                if(y != 0)
                    size *= 2;
                ans += size;
            }
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
