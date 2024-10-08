#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

class Solution {
    // int maxHigherPower(int n, int k) {
    //     int count = 0;
    //     bool lower = false;
    //     while(n) {
    //         if(n % k)
    //             lower = true;
    //         n /= k;
    //         count++;
    //     }
    //     return count - lower;
    // }
    public:
    void solve() {
        int n, k;
        cin >> n >> k;
        if(k == 1 || n < k) {
            cout<<n<<endl;
            return;
        }
        int count = 0;
        while(n) {
            count += n % k;
            n /= k;
        }
        cout << count << endl;
        
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