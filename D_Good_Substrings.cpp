#include <bits/stdc++.h>
#define int long long
using namespace std;

class RollingHash {
    vector<int> prefix;
    vector<int> modInverseVal;
    public:
    int power(int x, int n, const int mod = 1e9 + 7) {
        int calcPower = 1;
        int powerV = x;

        for(int i = 0; i <= 30; i++) {
            int bit = 1ll << i;
            if(bit & n) {
                calcPower *= powerV;
                calcPower %= mod;
            }
            powerV *= powerV;
            powerV %= mod;
        }

        return calcPower;
    }
    int modInverse(int x, const int mod = 1e9 + 7) {
        return power(x, mod-2, mod);
    }
    public:
    RollingHash(string& st, const int prime = 31, const int mod = 1e9 + 7) {
        int n = st.size();
        prefix.resize(n+1);
        modInverseVal.resize(n);

        int p = 1;
        for(int i = 0; i < n; i++) {
            prefix[i+1] = (p * (st[i] - 'a' + 1) + prefix[i]) % mod;
            modInverseVal[i] = modInverse(p, mod);
            p *= prime; p %= mod;
        }
    }
    int findHash(int i, int j, const int mod = 1e9 + 7) {
        int hash1 = prefix[i];
        int hash2 = prefix[j+1];

        int currHash = ((hash2 + mod - hash1) % mod * modInverseVal[i]) % mod;
        return currHash;
    }
};
class Solution {
    public:
    void solve() {
        string st, valid;
        cin >> st >> valid;
        int k;
        cin >> k;
        const int mod = 1e9 + 7;
        RollingHash rh1(st), rh2(st);
        int n = st.size();

        set<pair<int, int>> hashedValues;
        for(int i = 0; i < n; i++) {
            int wrong = 0;
            for(int j = i; j < n; j++) {
                wrong += valid[st[j] - 'a'] == '0';
                // cout<<st.substr(i, j-i+1)<<endl;
                // cout<<wrong<<" till above "<<endl;
                if(wrong > k)
                    break;
                
                int hashValue1 = rh1.findHash(i, j);
                int hashValue2 = rh2.findHash(i, j);
                hashedValues.insert(make_pair(hashValue1, hashValue2));
            }
        }

        cout<<hashedValues.size();
    }
};

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testCases = 1;
    // cin >> testCases;

    while (testCases--) {
        Solution obj;
        obj.solve();
    }

    return 0; 
}
