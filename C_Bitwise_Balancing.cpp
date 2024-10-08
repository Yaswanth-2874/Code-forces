#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

class Solution {
    // I THINK I WILL GET WA BCS DIDNT CONSIDER BORROW
    public:
    void solve() {
        int b, c, d;
        cin >> b >> c >> d;

        int a = 0;
        int borrow = 0;

        // CONSTRUCT FROM SMALL
        for(int i = 0; i <= 61; i++) {
            // cout<<i<<endl;
            int bBit = ((1LL << i) & b) > 0;
            int cBit = ((1LL << i) & c) > 0;
            int dBit = ((1LL << i) & d) > 0;

            // cout<<": "<<bBit<<" , "<<cBit<<" , "<<dBit<<" "; 
                int aBit = 0;
                if((aBit | bBit) - (aBit & cBit) == dBit) {
                    // cout<<aBit<<endl;
                    continue;
                }
                aBit = 1;
                if((aBit | bBit) - (aBit & cBit) == dBit) {
                    // cout<<aBit<<endl;
                    a += (1LL << i);
                    continue;
                }
                cout<<-1<<endl;
                return;
        }
        cout<<a<<endl;

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

