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
        string st;
        cin >> st;
        char prev = '#';
        vector<int> prefix;

        int count = 0;
        for(auto& ch : st) {
            if(ch == prev && ch == 'v')
                count++;
            prefix.push_back(count);
            prev = ch;
        }
        int occurances = 0;

        for(int i = 2; i < (int)st.size() - 2; i++) {
            if(st[i] == 'o') {
                int prevWs = prefix[i-1];
                int nextWs = prefix[st.size() - 1] - prefix[i];
                occurances += prevWs * nextWs;
            }
        }
        pn(occurances)
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}
