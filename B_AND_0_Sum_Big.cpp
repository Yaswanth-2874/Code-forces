#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define int long long
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define full(array) array.begin(), array.end()
#define input(array) for(auto& d : array)cin>>d;
#define print(array) for(auto& num : array) cout<<num<<" "; cout<<endl;

int power(int num,int pow) {
    if(pow == 0)
        return 1;
    if(pow == 1)
        return num;
            
    int calculatedPower = power(num, pow/2) % MOD;
    calculatedPower *= (calculatedPower %MOD);
    calculatedPower %= MOD;
        
    if(pow % 2) {
        calculatedPower *= (num % MOD);
        calculatedPower %= MOD;
    }
    return calculatedPower;
}

class Solution {
    public:
    void solve() {
        int n, k;
        cin >> n >> k;
        cout<<power(n, k)<<endl;
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
