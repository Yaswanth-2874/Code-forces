#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        string a, b;
        cin >> n;
        cin >> a >> b;

        int perfect1 = 0, perfect0 = 0;

        for(int i = 0; i < n; i++) {
            perfect0 += (a[i] == b[i] && a[i] == '0');
            perfect1 += (a[i] == b[i] && a[i] == '1');
        }
        int normal = n - perfect0 - perfect1;

        // if i can somehow balance perfect 0 and perfect 1, then my task is already done
        // impossible to balance if both perfect 0 and perfect 1 are odd

        if(perfect0 % 2 == 1 && perfect1 % 2 == 1)
            /* Print no*/ {
                cout<<"NO\n";
                return;
            }
        if(normal % 2 == 1 && (perfect0 % 2 == 1 || perfect1 % 2 == 1))
            /* Print no*/ {
                cout<<"NO\n";
                return;
            }
        /* Print yes*/ {
            cout<<"YES\n";
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
