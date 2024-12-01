#include <bits/stdc++.h>
using namespace std;

#pragma region Macros
#define MOD 1000000007
// #define int long long
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

// Math implementation is confusing, better alternative soln, just thought of it
vector<int> prefixAns;

int log3(int num) {
    int count = 0;
    while(num) {
        num /= 3;
        count++;
    }
    return count;
}

class Solution {
    public:
    void solve() {
        int l, r;
        cin >> l >> r;
        int extra = log3(l);

        pn(prefixAns[r] - prefixAns[l-1] + extra)
    }
};

int32_t main() {
    prefixAns.push_back(0);
    for(int i = 1; i <= 2e5; i++) {
        int newVal = prefixAns.back() + log3(i);
        prefixAns.push_back(newVal);
    }
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