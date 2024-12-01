#include <bits/stdc++.h>
using namespace std;

#define int long long
#define printAns(ans) {cout<<"! "<<ans<<endl; return;}


class Solution {
    int query(int a, int b) {
        cout<<"? "<<a<<" "<<b<<endl;
        cout.flush();
        int res;
        cin >> res;
        return res;
    }
    void findAns(string& ans, int n, int l, int r) {
        int q = query(l, r);
        while(q == 0) {
            l--;
            if(l == 0)
                printAns("IMPOSSIBLE");
            q = query(l, r);
        }
        ans[l-1] = '0';
        int onesAfter = q;
        for(int i = l; i < r; i++) {
            if(onesAfter) {
                onesAfter--;
                ans[i] = '1';
            } else {
                ans[i] = '0';
            }
        }
        int previousQueryAns = q;
        l--;

        while(l != 0) {
            int q = query(l, r);
            if(q == previousQueryAns) {
                ans[l-1] = '1';
            } else {
                previousQueryAns = q;
                ans[l-1] = '0';
            }
        }
        cout<<"! "<<ans<<endl;

    }
    public:
    void solve() {
        int n;
        cin >> n;

        int l = n-1, r = n;
        
        string ans = "";
        for(int i = 0; i < n; i++)
            ans.push_back('#');
        findAns(ans, n, l, r);
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

