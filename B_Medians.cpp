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

//The length of subarrays can change, it is not necessary for all subarrays to be of same length

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;
        if(n == 1) {
            cout<<1<<endl;
            pn(1);
        }

        if(k == 1 || k == n)
            pn(-1);
        cout<<3<<endl;
        int elementsBefore = k-1;
        if(elementsBefore % 2) {
            cout<<1<<" "<<k<<" "<<k+1<<endl;
            return;
        }
        cout<<1<<" "<<(k-1)<<" "<<(k+2)<<endl;
        //if k == n-1 then elements before would always be odd 
        //if k == n-2, then k+2 is always valid
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


