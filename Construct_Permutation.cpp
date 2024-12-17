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
        int n;
        cin >> n;

        int totalSum = (n * (n + 1)) / 2;
        if(totalSum % (n+1) == 0)
            pn(-1);

        vector<int> ans(n);
        int left = 1, right = n;
        bool leftTurn = true;
        // for even numbers it is not possible
        // for odd numbers there are n couples whose sum is (n+1)/2 
        // i should always isolate these couples
        // odd even odd even odd ...
        bool swapi = false;
        for(int i = 0; i < n/2; i++) {
            int last = n - (i + 1);
            ans[i] = i+1;
            ans[last] = last + 1;
            if(swapi)
                swap(ans[i], ans[last]);
            swapi = !swapi;
        }
        ans[n/2] = (n+1)/2;

        
        print(ans)
        
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
