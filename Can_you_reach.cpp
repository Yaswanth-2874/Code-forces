#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> v(n);
        for (auto& input : v) {
            cin >> input;
        }

        vector<int> extreme;
        for(int i = 1; i < n-1; i++) {
            if((v[i] > v[i-1] && v[i] > v[i+1]) || (v[i] < v[i-1] && v[i] < v[i+1]))
                extreme.push_back(i);
        }
        int ans = 0;
        extreme.push_back(n-1);
        extreme.push_back(-1);
        extreme.push_back(-1);
      
        int index = 0;
        // /* Print array*/ {
        //     for(auto& val : extreme) {
        //         cout << val << " ";
        //     }
        //     cout << endl;
        // }

        for(int i = 0; i < n; i++) {
            if(extreme[index] == i) {
                index++;
            }
            int next = extreme[index + 1] == -1 ? extreme[index] : extreme[index + 1];
            // cout<<next<<" for "<<i<<endl;
            if(next != -1) {
                int people = next - i;
                ans += people;
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
