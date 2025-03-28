#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    int colorsReqd(string& st, vector<int>& v, int target) {
        bool isRed = true;
        int colors = 0;

        for(int i = 0; i < v.size(); i++) {
            char color = st[i];
            if(color == 'B' && isRed) {
                if(v[i] > target) {
                    isRed = false;
                    colors++;
                }
            }
            if(!isRed && color == 'R') {
                if(v[i] > target) {
                    isRed = true;
                }
            }
        }

        return colors;
    }
    public:
    void solve() {
        int n, k;
        cin >> n >> k;

        string st;
        cin >> st;

        vector<int> v(n);
        for (auto& input : v) {
            cin >> input;
        }
        
        int low = 0, high = 1e15;

        while(low <= high) {
            int mid = low + (high - low)/2;
            int colors = colorsReqd(st, v, mid);
            if(colors > k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        int ans = high+1;
        cout<<ans<<endl;

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
