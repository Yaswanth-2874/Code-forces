#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#pragma endregion

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;

        vector<int> bits(31);

        for(int i = 0; i < n; i++) {
            int num;
            cin >> num;

            for(int bit = 0; bit < 31; bit++) {
                int bitValue = 1LL << bit;
                if(bitValue & num)
                    bits[bit]++;
            }
        }

        for(int i = 30; i >= 0; i--) {
            int& setBits = bits[i];
            int remainingBits = n - setBits;

            if(k >= remainingBits) {
                k -= remainingBits;
                setBits += remainingBits;
            }
        }
        int maximalAnd = 0;

        for(int i = 30; i >= 0; i--) {
            if(bits[i] == n)
                maximalAnd += 1LL << i;
        }

        pn(maximalAnd);
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
