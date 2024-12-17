#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) {for(auto& num : array) {cout<<num<<" ";} cout<<endl;}
#define pn(num){cout<<num<<endl; return;}
#define minHeap(var) var, vector<var>, greater<var>
#define exists(map, num) map.find(num) != map.end()
#define array(type, name, size) vector<type> name(size); input(name);
#define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
#define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
#pragma endregion

class Solution {
    public:
    void solve() {
        int n, l, r;
        cin >> n >> l >> r;
        array(int, v, n);
        // obv xor value
        int pro = 1;
        freqMap(int, v);
        for(auto& [_, s] : freq)
            if(s > 1) {
                if(l != 0)
                    no;
                yes;
            }

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                pro *= (v[i] ^ v[j]);
                // cout<<pro<<" ";
                if(pro > r)
                    no;
            }
            if(pro == 0)
                break;
        }

        if(pro < l)
            no;
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
