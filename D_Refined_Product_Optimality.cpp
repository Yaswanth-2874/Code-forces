#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;

class Solution {
    int n, q;
    int modExp(int base, int exp, int mod) {
        int result = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (1ll * result * base) % mod;
            base = (1ll * base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int modInverse(int x, int mod) {
        return modExp(x, mod - 2, mod);
    }
    int findMaxProduct(vector<int>& a, vector<int>& b) {
        sort(begin(a), end(a));
        sort(begin(b), end(b));

        int product = 1;
        for(int i = 0; i < n; i++) {
            product *= min(a[i], b[i]);
            product %= mod;
        }

        cout<<product<<" ";
        return product;
    }
    public:
    void solve() {
        cin >> n >> q;

        vector<int> a(n), b(n);
        vector<int> sortedA, sortedB;

        for (auto& input : a) {
            cin >> input;
        }

        for (auto& input : b) {
            cin >> input;
        }
        sortedA = a;
        sortedB = b;
        int p = findMaxProduct(sortedA, sortedB);

        while(q--) {
            int c, x;
            cin >> c >> x;
            
            if(c == 1) {
                int lastOccurancePos = prev(upper_bound(begin(sortedA), end(sortedA), a[x-1])) - begin(sortedA);
                int div = min(sortedA[lastOccurancePos], sortedB[lastOccurancePos]);
                p = (1LL * p * modInverse(div, mod)) % mod;
                sortedA[lastOccurancePos]++;
                p *= min(sortedA[lastOccurancePos], sortedB[lastOccurancePos]);
                p %= mod;
                a[x-1]++;
            } else {
                int lastOccurancePos = prev(upper_bound(begin(sortedB), end(sortedB), b[x-1])) - begin(sortedB);
                int div = min(sortedA[lastOccurancePos], sortedB[lastOccurancePos]);
                sortedB[lastOccurancePos]++;
                p = (1LL * p * modInverse(div, mod)) % mod;
                p *= min(sortedA[lastOccurancePos], sortedB[lastOccurancePos]);
                p %= mod;
                b[x-1]++;
            }
            cout<<p<<" ";
            // findMaxProduct(a, b);
        }
        cout<<endl;
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
