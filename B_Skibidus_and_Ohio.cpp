#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        string st;
        cin >> st;
        char prev = '#';

        // if consectutive characters match then return 1 else return size

        for(int i = 0; i < st.size() - 1; i++) {
            if(st[i] == st[i+1])
                /* Print number*/ {
                    cout<<1<<endl;
                    return;
                }
        }

        /* Print number*/ {
            cout<<st.size()<<endl;
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
