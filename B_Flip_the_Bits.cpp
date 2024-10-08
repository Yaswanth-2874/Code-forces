#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

// Target 110100
// 000111 -> reverse full prefix
// 111000 -> reverse prefix 4 (not possible bcs ones != zeroes)

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        bool reversed = false;
        int zeroes, ones = 0;
        for(char ch : a) {
            ones += ch == '1';
        }
        zeroes = n - ones;

        for(int i = n - 1; i >= 0; i--) {
            if(!reversed) {
                if(a[i] != b[i]) {
                    if(zeroes != ones)
                        no;
                    reversed = true;
                }
            } else {
                if(a[i] == b[i]) {
                    if(zeroes != ones)
                        no;
                    reversed = false;
                }
            }
            zeroes -= a[i] == '0';
            ones -= a[i] == '1';
        }
        yes;
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

