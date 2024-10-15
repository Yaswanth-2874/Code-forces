#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
#define yes {cout<<"YES\n"; return;}
#define no {cout<<"NO\n"; return;}
#define all(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;
#define pn(num){cout<<num<<endl; return;}

vector<int> fact;
class Solution {
    int fexp(int a, int b){
    int ans = 1;
    for(int i = 0; i < 35; i++){
        if(b&(1LL<<i)){
            ans *= a;
        }
        a *= a;
        a %= mod;
        ans %= mod;
    }
    return ans;
}

    int nCr(int N, int K){
        return fact[N] * fexp(fact[K] * fact[N-K] % mod, mod-2) % mod;
    }
    public:
    void solve() {
            int n, k, t;
            cin >> n >> k >> t;
            
            t /= 5;
            if(n > t)
                pn(0);
            int lastRow = t;
            int firstAdd = n - 1;
            int diff = n ;
            // cout<<lastRow<<"C"<<diff<<endl;
            int ans = ((nCr(lastRow, diff) % mod) * (k % mod)) % mod;
            cout<<ans<<endl;
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    int n = 1;
    fact = vector<int> (100000);
    fact[0] = 1;
    for(int i = 1; i < 100000; i++){
        fact[i] = fact[i-1] * i;
        fact[i] %= mod;
    }
    while (t--) {
        Solution obj;
        obj.solve();
    }
    return 0; 
}

