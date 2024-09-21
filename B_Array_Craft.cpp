
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
        int n, l ,r;
        cin>>n>>r>>l;
 
        int index = 1;
    
        while(index < l) {
            cout<<-1<<" ";
            index++;
        }
        while(index >= l && index <= r) {
            cout<<1<<" ";
            index++;
        }
        while(index > r  && index <= n) {
            cout<<-1<<" ";
            index++;
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