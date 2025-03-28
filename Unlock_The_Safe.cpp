#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;

        vector<int> given(n);
        for (auto& input : given) {
            cin >> input;
        }

        vector<int> target(n);
        for (auto& input : target) {
            cin >> input;
        }

        vector<int> up(n), down(n);
        set<int> diff;
        int minMoves = 0;

        for(int i = 0; i < n; i++) {
            int& a = given[i], &b = target[i];

            up[i] = abs(a - b);
            down[i] = 9 - up[i];
            diff.insert(abs(up[i] - down[i]));

            minMoves += min(up[i], down[i]);
        }

        if(minMoves > k)
            /* Print no*/ {
                cout<<"NO\n";
                return;
            }
        if((k - minMoves) % 2 == 0)
            /* Print yes*/ {
                cout<<"YES\n";
                return;
            }
        int differ = k - minMoves;
        
        for(int i = 1; i < 10; i+=2) {
            if(diff.count(i)) {
                if(i <= differ)
                /* Print yes*/ {
                    cout<<"YES\n";
                    return;
                }   
            }
        }
        /* Print no*/ {
            cout<<"NO\n";
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
