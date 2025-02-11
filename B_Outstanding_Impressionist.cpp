#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<pair<int, int>> vp;
        multiset<int> st;
        set<int> free;

        string ans = "";
        for(int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            vp.push_back({l, r});

            if(l == r)
                st.insert(l);
        }

        for(int i = 1; i <= 2*n; i++) {
            if(st.find(i) == st.end()) {
                free.insert(i);
            }
        }

        for(auto& [x, y] : vp) {
            bool erased = false;
            if(x == y) {
                st.erase(st.find(x));
                erased = true;
                if(st.find(x) == st.end()) {
                    free.insert(x);
                }

            }
            auto best = free.lower_bound(x);
            if(best == free.end() || *best > y) 
                ans.push_back('0');
            else
                ans.push_back('1');
            if(erased) {
                st.insert(x);
                free.erase(x);
            }
        }
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
