#include <bits/stdc++.h>
#define int long long
using namespace std;

class Solution {
    public:
    void solve() {
        string st;
        cin >> st;

        char prev = '#';
        int moves = 0;
        int ones = 0, zeroes = 0;
        int invalidPos = 0;

        for(auto ch : st) {
            ones += ch == '1';
            zeroes += ch == '0';

            if(prev == ch) {
                moves = 1;
            }
            prev = ch;
        }
        
        int optimal = (st.size()+1)/2;
        int extra = max(ones, zeroes) - optimal;

        if(abs(ones-zeroes) <= 1) {
           cout<<moves<<endl;
        } else if (extra <= 1) {
            cout<<2<<endl;
        } else
            cout<<3<<endl;
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
