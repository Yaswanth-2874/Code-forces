#include <bits/stdc++.h>
using namespace std;

#define int long long
#define printAns(ans) {cout<<"! "<<ans<<endl; return;}

class Solution {
    //  [5,1,4,2,3]
    int query(int a, int b) {
        cout<<"? "<<a<<" "<<b<<endl;
        cout.flush();
        int res;
        cin >> res;
        return res;
    }
    public:
    void solve() {
        int n;
        cin >> n;

        int l = 1, r = n;
        int secondMinPos = query(l, r);
        // my answer would either be between 1 and secondPos-1 or secondPos+1 or n inclusive
        // always query from secondminPos, if the query result changes, then it means that my second min is not second min in that segment, so ignore it

        bool presentInFirst = false;
        if(secondMinPos == 1) {
            l = 2;
        } else {
            int q = query(1, secondMinPos);
            if(q == secondMinPos) {
                presentInFirst = true;
                r = secondMinPos - 1;
            } else {
                l = secondMinPos + 1;
            }
        }

        while(l <= r) {
            int mid = l + (r - l)/2;
            int q1 = min(secondMinPos, mid);
            int q2 = max(secondMinPos, mid);
            // cout<<l<<" "<<r<<endl;

            int q = query(q1, q2);
            if(q == secondMinPos) {
                //if this is true, then max number already exists in the interval that i checked
                if(presentInFirst) {
                    l = mid + 1;
                    // ill reduce the search interval and try to find it in new location
                } else {
                    r = mid - 1;
                }
            } else {
                if(presentInFirst) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }    
        }
        if(presentInFirst) {
            printAns(r);
            return;
        }
        printAns(r + 1);
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

