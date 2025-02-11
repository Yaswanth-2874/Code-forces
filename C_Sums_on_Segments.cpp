#include <bits/stdc++.h>
#define int long long
using namespace std;

// perhaps i would have given up in actual contest

class Solution {
    int kadanes(vector<int>& v, int left, int right, int mul) {
        if(left == -1)
            return 0;

        int sum = 0, c = 0, l = left;
    
        for(int r = left; r < right; r++) {
            sum += v[r];
            while(l <= r && (mul == -1 ? sum > 0 : sum < 0)) {
                sum -= v[l++];
            }
            // cout<<sum<<" ";
            c = max(c, mul * sum);
        }

        // cout<<c<<endl;
        return c;
    }

    public:
    void solve() {
        int n;
        cin >> n;
        
        vector<int> v(n);
        int index = 0, xIndex = -69;
        for (auto& input : v) {
            cin >> input;
            if(input != -1 && input != 1)
                xIndex = index;
            index++;
        }
        int cplus = 0, cminus = 0;

        if(xIndex != -69) {
            cplus = max(kadanes(v, 0, xIndex, 1), kadanes(v, xIndex + 1, n, 1));
            cminus = max(kadanes(v, 0, xIndex, -1), kadanes(v, xIndex + 1, n, -1));
        } else {
            cplus = kadanes(v, 0, n, 1);
            cminus = kadanes(v, 0, n, -1);
        }
        
        set<int> ans;
        int left = -cminus, right = cplus;
        while(left <= right) {
            ans.insert(left++);
        }
        
        int sum = 0;
        if(xIndex != -69) {
           // i must include xIndex and find out max and min sum
            int minLeft = 0, maxLeft = 0;
            int minRight = 0, maxRight = 0;
            int sum = 0;

            for(int i = xIndex - 1; i >= 0; i--) {
                sum += v[i];
                minLeft = min(sum, minLeft);
                maxLeft = max(sum, maxLeft);
            }
            sum = 0;
            for(int i = xIndex + 1; i < n; i++) {
                sum += v[i];
                minRight = min(sum, minRight);
                maxRight = max(sum, maxRight);
            }

            // cout<<minLeft<<" "<<minRight<<" "<<maxLeft<<" "<<maxRight<<endl;
            int left = v[xIndex] + (minLeft + minRight);
            int right = v[xIndex] + (maxLeft + maxRight);
            
            while(left <= right) {
                ans.insert(left++);
            }      
        }
        cout<<ans.size()<<endl;
        /* Print array*/ {
            for(auto& val : ans) {
                cout << val << " ";
            }
            cout << endl;
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
