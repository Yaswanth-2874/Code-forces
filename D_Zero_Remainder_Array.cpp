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
        int n, k;
        cin >> n >> k;
        array(int, v, n);

        for(int& num : v) {
            num %= k;
            num = k - num;
            if(num == k)
                num = 0;
        }

        freqMap(int, v);
        int ans = 0;
        int extra = 0;

        for(auto& [num, f] : freq) {
            // i need to add (num) for each occurance of f
            // reqd operations  would be the number of additions im doing on last occurance of f
            if(num == 0)
                continue;
            
            extra = 1;
            int operations = (f - 1)*(k) + num;
            ans = max(ans, operations);
        }

        pn(ans + extra);
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
