#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    
    public:
    void solve() {
        int n;
        cin >> n;

        // can only add 9, 99, 999 ....
        // try to get 7
        int movesA = 9;
        int nCopy = n;
        int inc = 9;

        for(int i =0; i <= 10; i++) {
            int moves = 0;
            n = nCopy;
            // cout<<inc<<endl;
            for(int i = 1; i <= 10; i++) {
                string st = to_string(n);
                int ct = count(begin(st), end(st), '7');
                if(ct >= 1) {
                    movesA = min(movesA, moves);
                }
                moves++;
                n += inc;
            }
            inc *= 10;
            inc += 9;
        }
        /* Print number*/ {
            cout<<movesA<<endl;
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
