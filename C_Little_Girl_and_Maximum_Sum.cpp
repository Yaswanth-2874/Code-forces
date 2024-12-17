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
#define array(type, name, size) vector<type> name(size); input(name);
#define freqMap(firstType, input) map<firstType, int> freq; for(auto& ele : input) freq[ele]++;
#define nameFreqMap(firstType, input, name) map<firstType, int> name; for(auto& ele : input) name[ele]++;
#pragma endregion

class Solution {
    public:
    void solve() {
        int n, q;
        cin >> n >> q;
        array(int, v, n);

        vector<int> diffArray(n+1, 0);
        while(q--) {
            int l, r;
            cin >> l >> r;
            l--;
            diffArray[l]++;
            diffArray[r]--;
        }
        vector<int> prefix;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += diffArray[i];
            prefix.push_back(sum);
        }
        sort(all(v));
        sort(all(prefix));

        int ans = 0;
        for(int i = 0 ; i < n; i++) {
            ans += v[i] * prefix[i];
        }
        pn(ans);
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