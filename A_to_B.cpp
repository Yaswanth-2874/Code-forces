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
        int x1, y1, z1, x2, y2, z2, k;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> k;
        
        vector<int> dist = {abs(x1-x2), abs(y1-y2), abs(z1-z2)};
        sort(all(dist));;
        int& x = dist[0];
        int& y = dist[1];
        int& z = dist[2];

        int ans = 2*x;
        z -= x;
        if(y > z)
            swap(y, z);
        
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}
