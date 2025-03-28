#include <bits/stdc++.h>
#define int long long
using namespace std;

// Changes made ->
    // Removed map which was redundant

class Solution {
    class RollingHash {
        vector<int> prefix;
        vector<int> modInverseValues;
        int n;
        int power(int x, int n, const int mod = 1e9 + 7) {
            int calcPower = 1;
            int currPower = x;
            for(int i = 0; i <= 30; i++) {
                int bit = 1ll << i;
                if(bit & n)
                    calcPower = ((1ll * calcPower % mod) * (1ll * currPower)) % mod;
                currPower = ((1ll * currPower % mod) * (1ll * currPower % mod)) % mod;
            }
            return calcPower;
        }
        int modInverse(int a, const int mod = 1e9 + 7) {
            return power(a, mod-2, mod);
        }
        public:
        RollingHash(string& st, int hashPrime = 31, int mod = 1e9 + 7) {
            n = st.size();
            prefix.resize(n+1, 0);
            int p = 1;
            for(int i = 0; i < st.size(); i++) {
                int value = p * (st[i] - 'a' + 1);
                prefix[i+1] = ((value % mod) + (prefix[i] % mod)) % mod;
                modInverseValues.push_back(modInverse(p, mod));
                p *= hashPrime;
                p %= mod;
            }
        }
        int findHash(int l, int r, int mod = 1e9 + 7) {
            if(l > r  || l >= n || r >= n)
                return -1;
            int modInv = modInverseValues[l];
            int hash1 = prefix[l];
            int hash2 = prefix[r+1];
            int res = (1ll * (hash2 - hash1 + mod) * modInv) % mod;
            return res;
        }
    };
    public:
    void solve() {
        string st;
        cin >> st;
        int n = st.size();

        RollingHash rh(st);
        vector<int> valid;
        
        for(int i = 0; i < n-1; i++) {
            int firstHash = rh.findHash(0, i);
            int lastHash = rh.findHash(n-1-i, n-1);

            if(firstHash == lastHash) {
                // cout<<st.substr(0, i+1)<<" is valid "<<endl;
                valid.push_back(i);
            }
        }
        int left = 0, right = (int)valid.size() - 1, ans = -1;

        while(left <= right) {
            int mid = left + (right - left)/2;
            int correct = valid[mid];
            int expectedHash = rh.findHash(0, correct);
            int r = n-1, l = n-1-correct;
            l--; r--;
            bool possible = false;
            // cout<<"Checking for "<<st.substr(0, correct)<<endl;

            while(l > 0) {
                int hash = rh.findHash(l, r);
                if(hash == expectedHash) {
                    possible = true;
                }
                l--; r--;
            }

            if(possible) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }

        if(ans == -1)
            cout<<"Just a legend";
        else
            for(int i = 0; i <= valid[ans]; i++)
                cout<<st[i];
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
