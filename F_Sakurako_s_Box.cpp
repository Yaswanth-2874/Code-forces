#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

// Function to compute modular inverse using Fermat's Little Theorem
ll mod_inverse(ll a, ll mod) {
    ll result = 1;
    ll exponent = mod - 2;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        exponent /= 2;
    }
    return result;
}

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    ll sum = 0;
    
    // Read input and compute sum
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum = (sum + nums[i]) % MOD;
    }
    
    // Compute S^2
    ll sum_squared = (sum * sum) % MOD;
    
    // Compute n^2
    ll n_squared = (static_cast<ll>(n) * n) % MOD;
    
    // Compute modular inverse of n^2
    ll n_squared_inv = mod_inverse(n_squared, MOD);
    
    // Compute the result
    ll result = (sum_squared * n_squared_inv) % MOD;
    
    // Output the result
    cout << result << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
