#include <bits/stdc++.h>
#define int long long
using namespace std;

class RollingHash {
    int power(int x, int n, int mod) {
        long long calcVal = 1, powerVal = x;
        for(int i = 0; i <= 30; i++) {
            int bit = 1ll << i;
            if(bit & n) {
                calcVal *= powerVal;
                calcVal %= mod;
            }
            powerVal *= powerVal;
            powerVal %= mod;
        }
        return calcVal;
    }
    int modInv(int x, int mod) {
        return power(x, mod-2, mod);
    }
    vector<int> prefix;
    vector<int> modInvVal;
    int mod;
    public:
    RollingHash(string& s, int p, int mod) {
        int n = s.size();
        this->mod = mod;

        prefix.resize(n+1, 0);
        int coeff = 1;
        // cout<<power(2, 10, 1e9)<<" is power "<<endl;
        // cout<<modInv(2, 1e9+7)<<" is mod inv"<<endl;
        cout<<modInv(p, mod)<<endl;
        for(int i = 0; i < n; i++) {
            int value = coeff * (s[i] - 'a' + 1);
            modInvVal.push_back(modInv(coeff, mod));
            coeff *= p;
            coeff %= mod;
            prefix[i+1] = (value + prefix[i]) % mod;
            cout<<prefix[i+1]<<" for prefix "<<s.substr(0, i+1)<<endl;
        }

    }
    int findHash(int i, int j) {
        int hash1 = prefix[i], hash2 = prefix[j+1];
        return ((hash2 + mod - hash1) * modInvVal[i]) % mod;
    }
};

class Solution {
    public:
    void solve() {
        string st;
        cin >> st;
        
        
        // int base = 31, mod = 89;
        int base = 31, mod = 100;
        // RollingHash rh(st, base, mod);
        // // cout<<rh.findHash(0, 5)<<endl;
        // cout<<rh.findHash(1, 4)<<endl;

        int sum = 0;
        for(int i = 0; i < st.size(); i++) {
            int power = pow(base, i);
            sum += power * (st[i] - 'a' + 1);
        }
        cout<<sum<<" and "<<sum%mod<<endl;

    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
