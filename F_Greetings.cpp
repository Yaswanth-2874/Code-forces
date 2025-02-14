#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#pragma endregion

class Solution {
    public:
    void solve() {
        int n;
        cin >> n;

        vector<pair<int, int>> moves(n);
        ordered_set stops;

        for(int i = 0; i < n; i++) {
            cin >> moves[i].first >> moves[i].second;
            stops.insert(moves[i].second);
        }

        sort(all(moves));
        int greetings = 0;

        for(auto& [start, end] : moves) {
            auto endPos = stops.lower_bound(end);

            int people = stops.order_of_key(*endPos) ;
            greetings += people;
            stops.erase(end);
        }
        pn(greetings);

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
