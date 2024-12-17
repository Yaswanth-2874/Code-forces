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
        int n, m, d;
        cin >> n >> m >> d;

        array(int, v, n);
        map<int, int> ans;

        set<pair<int, int>> values;
        for(int i = 0; i < n; i++)
            values.insert({v[i], i});
        
        int day = 1;
        while(!values.empty()) {
            auto [val, index] = *values.begin();
            auto nextIt = values.lower_bound({val + d + 1, -69});
            values.erase(values.find({val, index}));
            ans[index] = day;

            while(nextIt != values.end()) {
                auto [val, index] = *nextIt;
                values.erase(values.find({val, index}));
                nextIt = values.lower_bound({val+d + 1, -69});
                ans[index] = day;
            }
            
            day++;
        }
        cout<<day-1<<endl;
        for(auto& [index, dayV] : ans) {
            cout<<dayV<<" ";
        }
        cout<<endl;
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
