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
    bool leftSearch(int index) {
        
    }

    public:
    void solve() {
        int n;
        cin >> n;

        vector<int> v(n);
        input(v);

        for(int i = 0; i < n; i++) {
            int prev = -69, next = -69;
            if(i)
                prev = v[i-1];
            if(i + 1 < n) 
                next = v[i+1];  
            if(v[i] == i+1)
                continue;
            if(next == i+1 && abs(v[i] - next) == 1) {
                swap(v[i], v[i+1]);
                continue;
            }
            if(prev == i+1 && abs(v[i] - next) == 1) {
                swap(v[i-1], v[i+1]);
                continue;
            }
            no;
        }
        yes;
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
