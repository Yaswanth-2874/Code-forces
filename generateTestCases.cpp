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
#define array(name, size) vector<int> v(size); input(v);
#pragma endregion

class Solution {
    public:
    void solve() {
        
        int l = rand() % 10000 + 1;
        int r = rand() % 10000 + l;

        cout<<l<<" "<<r<<endl;
    }
};


int32_t main() {
    srand(static_cast<unsigned int>(time(0)));
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 100;
    cin >> t;
    cout<<t<<endl;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}
