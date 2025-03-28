#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        string a, b, c;
        cin >> a >> b >> c;

        int onesA = count(begin(a), end(a), '1'), zeroesA = n - onesA;
        int onesB = count(begin(b), end(b), '1'), zeroesB = n - onesB;
        int onesC = count(begin(c), end(c), '1'), zeroesC = n - onesC;

        int totalOnes = onesA + onesB + onesC;
        if(totalOnes == 0 || totalOnes == 3*n) {
            /* Print number*/ {
                cout<<0<<endl;
                return;
            }
        }
        if(totalOnes != n && totalOnes != 2*n) {
            /* Print number*/ {
                cout<<-1<<endl;
                return;
            }
        }

        if(totalOnes == n) {
            /* Print number*/ {
                cout<<min({zeroesA, zeroesB, zeroesC})<<endl;
                return;
            }
        }
        cout<<min({onesA, onesB, onesC})<<endl;

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
