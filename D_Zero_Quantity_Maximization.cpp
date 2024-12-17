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

// Maybe the mistake is not with implementation, logic could be the issue

class Solution {
    pair<int, int> findOptimal(int a, int b) {
        bool isNegative = (a < 0) != (b < 0);
        a = abs(a);
        b = abs(b);
        int gcd = __gcd(a, b);

        a /= gcd;
        b /= gcd;
        if(isNegative)
            a *= -1ll;

        // cout<<a<<"/"<<b<<endl;
        return {a, b};
    }
    public:
    void solve() {
        int n;
        cin >> n;
        array(int, a, n);
        array(int, b, n);
        int maxFreq = 0;
        int zeroes = 0;

        map<pair<int, int>, int> freq;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(b[i] == 0) {
                ans += a[i] == 0;
                zeroes += a[i] != 0;
                continue;
            }
            if(a[i] == 0) {
                continue;
            }
            auto opt = findOptimal(a[i], b[i]);
            maxFreq = max(maxFreq, ++freq[{opt}]);
        }
        maxFreq = max(maxFreq, zeroes);
          
        ans += maxFreq;
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