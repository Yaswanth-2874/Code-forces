
#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(int num : array) cout<<num<<" "; cout<<endl;
 
class Solution {
    public:
    void solve() {
        int n, x, y;
        cin >> n >> x >> y;

        // max prefix pos is x, so sum after x should be atmost 0
        // max suffix pos is y, so sum before y should be atmost 0

        // i can simply place all -1 after x and before y
        // the problem is if there are not enough positive ones, then my answer fails
        // to fix this, ill try to minimise the negative sum 
        int curr = -1;
        if((y-1) % 2 == 0)
            curr = 1;
        else
            curr = -1;
        
        for(int i = 1; i < y; i++) {
            cout<<curr<<" ";
            curr *= -1;
        }
        for(int i = y; i <= x; i++) 
            cout<<1<<" ";

        // i should start with a negative number
        curr = -1;
        for(int i = x+1; i <= n; i++) {
            cout<<curr<<" ";
            curr *= -1;
        }
        cout<<endl;
    }
};
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0;
}